--中间九日表格核心操作

--用户行为类型分布
SELECT behavior_type, COUNT(*) AS total
FROM user_behavior_mid9days
GROUP BY behavior_type
ORDER BY total DESC;


--用户行为漏斗分析
--行为转化路径
SELECT 
    behavior_type,
    COUNT(DISTINCT user_id) AS unique_users
FROM user_behavior_mid9days
WHERE behavior_type IN ('pv', 'cart', 'buy')
GROUP BY behavior_type;


--每天各行为分布趋势
SELECT 
    toDate(ts) AS date,
    behavior_type,
    COUNT(*) AS cnt
FROM user_behavior_mid9days
GROUP BY date, behavior_type
ORDER BY date ASC, behavior_type;




--每日行为用户数量
SELECT
    toDate(ts) AS date,
    behavior_type,
    uniqExact(user_id) AS user_count
FROM user_behavior_mid9days
WHERE behavior_type IN ('pv', 'cart', 'buy','fav')
GROUP BY date, behavior_type
ORDER BY date, behavior_type;




--pv~cart~buy路径上的行为转化率
SELECT
    pv.date,
    pv.users_pv,
    cart.users_cart,
    buy.users_buy,
    round(cart.users_cart / pv.users_pv, 4) AS pv_to_cart_rate,
    round(buy.users_buy / cart.users_cart, 4) AS cart_to_buy_rate,
    round(buy.users_buy / pv.users_pv, 4) AS pv_to_buy_rate
FROM
    (SELECT toDate(ts) AS date, uniqExact(user_id) AS users_pv
     FROM user_behavior_mid9days
     WHERE behavior_type = 'pv'
     GROUP BY date) AS pv
LEFT JOIN
    (SELECT toDate(ts) AS date, uniqExact(user_id) AS users_cart
     FROM user_behavior_mid9days
     WHERE behavior_type = 'cart'
     GROUP BY date) AS cart
ON pv.date = cart.date
LEFT JOIN
    (SELECT toDate(ts) AS date, uniqExact(user_id) AS users_buy
     FROM user_behavior_mid9days
     WHERE behavior_type = 'buy'
     GROUP BY date) AS buy
ON pv.date = buy.date

ORDER BY pv.date;



--九天各小时粒度的漏斗视图
SELECT
    toStartOfHour(ts) AS hour,
    behavior_type,
    uniqExact(user_id) AS user_count
FROM user_behavior_mid9days
WHERE behavior_type IN ('pv', 'cart', 'buy')
GROUP BY hour, behavior_type
ORDER BY hour;



--九天合并统计：每小时 × 行为 类型 分布(chat)
SELECT
    toHour(ts) AS hour,
    behavior_type,
    COUNT(*) AS count
FROM user_behavior_mid9days
GROUP BY hour, behavior_type
ORDER BY hour, behavior_type;



--九天合并统计：每小时 × 行为 类型 分布(db)
SELECT
    toHour(ts) AS hour,
    SUM(CASE WHEN behavior_type = 'pv' THEN 1 ELSE 0 END) AS pv_count,
    SUM(CASE WHEN behavior_type = 'cart' THEN 1 ELSE 0 END) AS cart_count,
    SUM(CASE WHEN behavior_type = 'buy' THEN 1 ELSE 0 END) AS buy_count,
    SUM(CASE WHEN behavior_type = 'fav' THEN 1 ELSE 0 END) AS fav_count
FROM
    user_behavior_mid9days
GROUP BY
    hour
ORDER BY
    hour;


--2017年12月02日单日二十四小时行为统计（建模）
SELECT
    toHour(ts) AS hour,
    behavior_type,
    COUNT(*) AS count
FROM user_behavior_mid9days
WHERE ts >= '2017-12-02 00:00:00'
  AND ts < '2017-12-03 00:00:00'
GROUP BY hour, behavior_type
ORDER BY hour, behavior_type;



--2017年12月02日周六单日二十四小时行为统计（作图）
SELECT
    toHour(ts) AS hour,
    SUM(CASE WHEN behavior_type = 'pv' THEN 1 ELSE 0 END) AS pv_count,
    SUM(CASE WHEN behavior_type = 'cart' THEN 1 ELSE 0 END) AS cart_count,
    SUM(CASE WHEN behavior_type = 'buy' THEN 1 ELSE 0 END) AS buy_count,
    SUM(CASE WHEN behavior_type = 'fav' THEN 1 ELSE 0 END) AS fav_count
FROM
    user_behavior_mid9days
WHERE
    toDate(ts) = '2017-12-02'
GROUP BY
    hour
ORDER BY
    hour;


--一周行为趋势(gpt)
SELECT
    toDate(ts) AS date,
    behavior_type,
    COUNT(*) AS count
FROM user_behavior_mid9days
WHERE ts >= '2017-11-27 00:00:00'
  AND ts <= '2017-12-03 23:59:59'
GROUP BY date, behavior_type
ORDER BY date, behavior_type;




--2017年11月28日周二单日二十四小时行为统计（作图）
SELECT
    toHour(ts) AS hour,
    SUM(CASE WHEN behavior_type = 'pv' THEN 1 ELSE 0 END) AS pv_count,
    SUM(CASE WHEN behavior_type = 'cart' THEN 1 ELSE 0 END) AS cart_count,
    SUM(CASE WHEN behavior_type = 'buy' THEN 1 ELSE 0 END) AS buy_count,
    SUM(CASE WHEN behavior_type = 'fav' THEN 1 ELSE 0 END) AS fav_count
FROM
    user_behavior_mid9days
WHERE
    toDate(ts) = '2017-11-28'
GROUP BY
    hour
ORDER BY
    hour;




--2017年11月30日周四单日二十四小时行为统计（作图）
SELECT
    toHour(ts) AS hour,
    SUM(CASE WHEN behavior_type = 'pv' THEN 1 ELSE 0 END) AS pv_count,
    SUM(CASE WHEN behavior_type = 'cart' THEN 1 ELSE 0 END) AS cart_count,
    SUM(CASE WHEN behavior_type = 'buy' THEN 1 ELSE 0 END) AS buy_count,
    SUM(CASE WHEN behavior_type = 'fav' THEN 1 ELSE 0 END) AS fav_count
FROM
    user_behavior_mid9days
WHERE
    toDate(ts) = '2017-11-30'
GROUP BY
    hour
ORDER BY
    hour;


--2017年12月1日周五单日二十四小时行为统计（作图）
SELECT
    toHour(ts) AS hour,
    SUM(CASE WHEN behavior_type = 'pv' THEN 1 ELSE 0 END) AS pv_count,
    SUM(CASE WHEN behavior_type = 'cart' THEN 1 ELSE 0 END) AS cart_count,
    SUM(CASE WHEN behavior_type = 'buy' THEN 1 ELSE 0 END) AS buy_count,
    SUM(CASE WHEN behavior_type = 'fav' THEN 1 ELSE 0 END) AS fav_count
FROM
    user_behavior_mid9days
WHERE
    toDate(ts) = '2017-12-01'
GROUP BY
    hour
ORDER BY
    hour;


--2017年12月3日周日单日二十四小时行为统计（作图）
SELECT
    toHour(ts) AS hour,
    SUM(CASE WHEN behavior_type = 'pv' THEN 1 ELSE 0 END) AS pv_count,
    SUM(CASE WHEN behavior_type = 'cart' THEN 1 ELSE 0 END) AS cart_count,
    SUM(CASE WHEN behavior_type = 'buy' THEN 1 ELSE 0 END) AS buy_count,
    SUM(CASE WHEN behavior_type = 'fav' THEN 1 ELSE 0 END) AS fav_count
FROM
    user_behavior_mid9days
WHERE
    toDate(ts) = '2017-12-03'
GROUP BY
    hour
ORDER BY
    hour;