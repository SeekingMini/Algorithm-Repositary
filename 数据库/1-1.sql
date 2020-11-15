/*
 * 题目：第二高的薪水
 * 链接：https://leetcode-cn.com/problems/second-highest-salary/
 */

select max(distinct Salary) as SecondHighestSalary
from Employee
where Salary < (select max(distinct Salary) from Employee);