-- 请先确保新表存在
CREATE TABLE IF NOT EXISTS new_user_behavior_mid9days_cleaned
ENGINE = MergeTree()
ORDER BY (date, hour) AS
SELECT 
    user_id, 
    item_id, 
    category_id, 
    behavior_type,
    ts,
    toTimeZone(ts, 'Asia/Shanghai') AS local_ts,
    toDate(toTimeZone(ts, 'Asia/Shanghai')) AS date,
    toHour(toTimeZone(ts, 'Asia/Shanghai')) AS hour
FROM user_behavior_mid9days
WHERE 1 = 0;  -- 初始化空表结构




INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-11-25'
) AS filtered;



INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-11-26'
) AS filtered;





INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-11-27'
) AS filtered;




INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-11-28'
) AS filtered;




INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-11-29'
) AS filtered;



INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-11-30'
) AS filtered;



INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-12-01'
) AS filtered;




INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-12-02'
) AS filtered;




INSERT INTO new_user_behavior_mid9days_cleaned
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
    SELECT DISTINCT 
        user_id, 
        item_id, 
        category_id, 
        behavior_type, 
        ts
    FROM user_behavior_mid9days
    WHERE behavior_type IN ('pv', 'buy', 'cart', 'fav')
      AND toDate(ts) = '2017-12-03'
) AS filtered;