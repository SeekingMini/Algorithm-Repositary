-- 题目：从不订购的客户
-- 链接：https://leetcode-cn.com/problems/customers-who-never-order/

-- 解法1
select c.Name as Customers
from Customers c
where c.Id not in (
    select o.CustomerId
    from Orders o
    );

-- 解法2
select c.Name as Customers
from Customers c
left join Orders o
on c.Id = o.CustomerId
where o.CustomerId is null;