-- 题目：上升的温度
-- 链接：https://leetcode-cn.com/problems/rising-temperature/

select w2.Id
from Weather w1, Weather w2
where DATEDIFF(w2.RecordDate, w1.RecordDate) = 1 and w2.Temperature > w1.Temperature;