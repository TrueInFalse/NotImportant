SELECT 
    toHour(toTimeZone(ts, 'Asia/Shanghai')) AS hour,
    COUNT(*) AS record_count
FROM new_user_behavior_mid9days_cleaned
WHERE toDate(toTimeZone(ts, 'Asia/Shanghai')) = '2017-12-01'
GROUP BY hour
ORDER BY hour;


SELECT 
    COUNT(DISTINCT user_id) AS active_user_count
FROM new_user_behavior_mid9days_cleaned
WHERE toDate(toTimeZone(ts, 'Asia/Shanghai')) = '2017-12-03';
