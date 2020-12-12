/*
 * 题目：大的国家
 * 链接：https://leetcode-cn.com/problems/big-countries/
 */

select name,population,area
from World
where area > 3000000 or population > 25000000;