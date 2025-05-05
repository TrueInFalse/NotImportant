
--目标是构建用户行为漏斗
SELECT
    count(DISTINCT pv_users.user_id) AS pv_user_count,
    count(DISTINCT cart_users.user_id) AS cart_user_count,
    count(DISTINCT buy_users.user_id) AS buy_user_count,
    round(
        count(DISTINCT cart_users.user_id) * 1.0 / count(DISTINCT pv_users.user_id), 
        4
    ) AS pv_to_cart_rate,
    round(
        count(DISTINCT buy_users.user_id) * 1.0 / count(DISTINCT cart_users.user_id), 
        4
    ) AS cart_to_buy_rate,
    round(
        count(DISTINCT buy_users.user_id) * 1.0 / count(DISTINCT pv_users.user_id), 
        4
    ) AS pv_to_buy_rate
FROM
    -- 完成浏览行为的用户
    (SELECT DISTINCT user_id FROM user_behavior_mid9days WHERE behavior_type = 'pv') AS pv_users
LEFT JOIN
    -- 在 pv 用户中，完成加购行为的用户
    (SELECT DISTINCT user_id FROM user_behavior_mid9days WHERE behavior_type = 'cart') AS cart_users
ON pv_users.user_id = cart_users.user_id
LEFT JOIN
    -- 在 cart 用户中，完成购买行为的用户
    (SELECT DISTINCT user_id FROM user_behavior_mid9days WHERE behavior_type = 'buy') AS buy_users
ON cart_users.user_id = buy_users.user_id
;


--查看时间格式时区
SELECT 
    ts,
    toDateTime(ts) AS default_time,
    toDateTime(ts, 'Asia/Shanghai') AS bj_time
FROM user_behavior_mid9days
ORDER BY ts
LIMIT 10;



-- 假设当前使用 ClickHouse
-- 表名：user_behavior_mid9days
-- 字段：user_id, item_id, category_id, behavior_type, ts

--窄格
-- 公共预处理建议：将ts字段提前转换为日期与小时字段供后续使用
-- 可在视图或子查询中复用

-- (1) 九日每日活跃用户数量（即每天UV）
SELECT
    toDate(ts) AS date,
    uniqExact(user_id) AS daily_active_users
FROM user_behavior_mid9days
GROUP BY date
ORDER BY date;

-- (2) 2017-11-28（周二）单日每小时各行为用户数量
SELECT
    toHour(ts) AS hour,
    behavior_type,
    uniqExact(user_id) AS user_count
FROM user_behavior_mid9days
WHERE toDate(ts) = '2017-11-28'
GROUP BY hour, behavior_type
ORDER BY hour, behavior_type;

-- (3) 2017-12-01（周五）单日每小时各行为用户数量
SELECT
    toHour(ts) AS hour,
    behavior_type,
    uniqExact(user_id) AS user_count
FROM user_behavior_mid9days
WHERE toDate(ts) = '2017-12-01'
GROUP BY hour, behavior_type
ORDER BY hour, behavior_type;

-- (4) 九日整体 每小时 各行为 用户数量分布（聚合所有天）
SELECT
    toHour(ts) AS hour,
    behavior_type,
    uniqExact(user_id) AS user_count
FROM user_behavior_mid9days
GROUP BY hour, behavior_type
ORDER BY hour, behavior_type;

-- (5) 七天每日 各行为 用户数量（2017-11-27 至 2017-12-03）
SELECT
    toDate(ts) AS date,
    behavior_type,
    uniqExact(user_id) AS user_count
FROM user_behavior_mid9days
WHERE toDate(ts) BETWEEN '2017-11-27' AND '2017-12-03'
GROUP BY date, behavior_type
ORDER BY date, behavior_type;




SELECT
    HOUR(ts) AS hour,              -- 直接提取小时，基于原始时间
    behavior_type,
    COUNT(DISTINCT user_id) AS user_count
FROM
    user_behavior_mid9days
WHERE
    DATE(ts) = '2017-11-28'         -- 按原始日期筛选
GROUP BY
    hour, behavior_type
ORDER BY
    hour, behavior_type;
