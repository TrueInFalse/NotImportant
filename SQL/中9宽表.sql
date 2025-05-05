
--（1）九日每日活跃用户数量
SELECT 
    toDate(ts) AS date,
    count(DISTINCT user_id) AS active_users
FROM user_behavior_mid9days
GROUP BY date
ORDER BY date;


--（2）2017-11-28 每小时各行为用户数量（宽表）
SELECT 
    toHour(ts) AS hour,
    count(DISTINCT if(behavior_type = 'pv', user_id, NULL)) AS pv_users,
    count(DISTINCT if(behavior_type = 'cart', user_id, NULL)) AS cart_users,
    count(DISTINCT if(behavior_type = 'fav', user_id, NULL)) AS fav_users,
    count(DISTINCT if(behavior_type = 'buy', user_id, NULL)) AS buy_users
FROM user_behavior_mid9days
WHERE toDate(ts) = '2017-11-28'
GROUP BY hour
ORDER BY hour;


--（3）2017-12-01 每小时各行为用户数量（宽表）
SELECT 
    toHour(ts) AS hour,
    count(DISTINCT if(behavior_type = 'pv', user_id, NULL)) AS pv_users,
    count(DISTINCT if(behavior_type = 'cart', user_id, NULL)) AS cart_users,
    count(DISTINCT if(behavior_type = 'fav', user_id, NULL)) AS fav_users,
    count(DISTINCT if(behavior_type = 'buy', user_id, NULL)) AS buy_users
FROM user_behavior_mid9days
WHERE toDate(ts) = '2017-12-01'
GROUP BY hour
ORDER BY hour;


--（4）九日汇总每小时各行为用户数量（宽表）
SELECT 
    toHour(ts) AS hour,
    count(DISTINCT if(behavior_type = 'pv', user_id, NULL)) AS pv_users,
    count(DISTINCT if(behavior_type = 'cart', user_id, NULL)) AS cart_users,
    count(DISTINCT if(behavior_type = 'fav', user_id, NULL)) AS fav_users,
    count(DISTINCT if(behavior_type = 'buy', user_id, NULL)) AS buy_users
FROM user_behavior_mid9days
GROUP BY hour
ORDER BY hour;


--（5）11月27日至12月3日 每日各行为用户数量（宽表）
SELECT 
    toDate(ts) AS date,
    count(DISTINCT if(behavior_type = 'pv', user_id, NULL)) AS pv_users,
    count(DISTINCT if(behavior_type = 'cart', user_id, NULL)) AS cart_users,
    count(DISTINCT if(behavior_type = 'fav', user_id, NULL)) AS fav_users,
    count(DISTINCT if(behavior_type = 'buy', user_id, NULL)) AS buy_users
FROM user_behavior_mid9days
WHERE toDate(ts) BETWEEN '2017-11-27' AND '2017-12-03'
GROUP BY date
ORDER BY date;



