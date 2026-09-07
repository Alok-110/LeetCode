# Write your MySQL query statement below
select class from (select class, count(class) as students from Courses group by class) as class where students >= 5;