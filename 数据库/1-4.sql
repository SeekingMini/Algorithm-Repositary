-- 题目：有趣的电影
-- 链接：https://leetcode-cn.com/problems/not-boring-movies/

select *
from cinema
where id % 2 = 1 and description not like '%boring%'
order by rating desc;