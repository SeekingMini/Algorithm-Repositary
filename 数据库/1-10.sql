-- 题目：超过5名学生的课
-- 链接：https://leetcode-cn.com/problems/classes-more-than-5-students/

select distinct c1.class
from courses c1
join (select class, COUNT(distinct student) as count
      from courses
      group by class) c2
on c1.class = c2.class and c2.count >= 5;