-- 题目：超过经理收入的员工
-- 链接：https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/submissions/

-- 解法1
select e1.Name as Employee
from Employee e1
where Salary > (
    select Salary
    from Employee e2
    where e2.id = e1.ManagerId
    );

-- 解法2
select e1.Name as Employee
from Employee e1, Employee e2
where e1.ManagerId = e2.Id and e1.Salary > e2.Salary;

-- 解法3
select e1.Name as Employee
from Employee e1
join Employee e2
on e1.ManagerId = e2.Id and e1.Salary > e2.Salary;