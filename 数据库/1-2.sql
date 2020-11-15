/*
 * 题目：查找重复的电子邮箱
 * 链接：https://leetcode-cn.com/problems/duplicate-emails/
 */

select Email
from (select Email, count(Email) as count
      from Person
      group by Email) as na
where na.count >= 2;