-- 向已存在的表中插入数据
INSERT INTO new_user_behavior_mid9days
SELECT 
    user_id, 
    item_id, 
    category_id, 
    behavior_type,
    ts,
    toTimeZone(ts, 'Asia/Shanghai') AS local_ts,
    toDate(toTimeZone(ts, 'Asia/Shanghai')) AS date,
    toHour(toTimeZone(ts, 'Asia/Shanghai')) AS hour
FROM (
    SELECT user_id, item_id, category_id, behavior_type, ts
    FROM user_behavior_mid9days  -- 假设原始表名为 user_behavior_mid9days
    WHERE toDate(ts) BETWEEN '2017-11-24' AND '2017-12-03'  -- 首先筛选出 2017-11-24 到 2017-12-03 的数据
) AS subquery1
WHERE toDate(toTimeZone(ts, 'Asia/Shanghai')) BETWEEN '2017-11-25' AND '2017-12-03'  -- 时区转换后再筛选出 2017-11-25 到 2017-12-03 的数据
GROUP BY 
    user_id, 
    item_id, 
    category_id, 
    behavior_type,
    ts,
    toTimeZone(ts, 'Asia/Shanghai'),
    toDate(toTimeZone(ts, 'Asia/Shanghai')),
    toHour(toTimeZone(ts, 'Asia/Shanghai'))
HAVING behavior_type IN ('pv', 'buy', 'cart', 'fav');