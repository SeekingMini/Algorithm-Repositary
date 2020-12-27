-- 题目：组合两个表
-- 链接：https://leetcode-cn.com/problems/combine-two-tables/

select p.FirstName, p.LastName, a.City, a.State
from person p
left join Address a
on p.PersonId = a.PersonId;