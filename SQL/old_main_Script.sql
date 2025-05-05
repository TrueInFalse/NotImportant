DESCRIBE user_behavior_simple;	--查看名为 user_behavior_simple 的表的结构信息。

SELECT * FROM user_behavior_simple LIMIT 10;	--查看表的前十行内容，看是否与预期正确

--查看时间范围
SELECT 	
  MIN(ts) AS earliest_time, 
  MAX(ts) AS latest_time
FROM user_behavior_simple;

--查看数据分布在那些年份
SELECT 
  toStartOfYear(ts) AS year, 
  COUNT(*) AS total_records
FROM user_behavior_simple
GROUP BY year
ORDER BY year;

--查看数据分布在哪些月份
SELECT 
  toStartOfMonth(ts) AS month, 
  COUNT(*) AS total_records
FROM user_behavior_simple
GROUP BY month
ORDER BY month;

--查看数据具体分布在哪些天
SELECT 
    toDate(ts) AS day,
    COUNT(*) AS total_records
FROM user_behavior_simple
WHERE ts >= '2017-11-01' AND ts < '2018-01-01'
GROUP BY day
ORDER BY day;


--新建子表，选择最为有效关键的数据
--DROP TABLE user_behavior_mid9days;

CREATE TABLE user_behavior_mid9days
ENGINE = MergeTree()
ORDER BY ts
AS
SELECT * FROM user_behavior_simple
WHERE ts BETWEEN '2017-11-25 00:00:00' AND '2017-12-03 23:59:59';


--查询新建表中间九日所占数据量
SELECT COUNT(*) FROM user_behavior_mid9days;

