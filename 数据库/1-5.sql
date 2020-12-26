-- 题目：变更性别
-- 链接：https://leetcode-cn.com/problems/swap-salary/

update salary
set sex = case sex
	when 'f' then 'm'
	else 'f'
	end;