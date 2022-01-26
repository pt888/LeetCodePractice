# Write your MySQL query statement below
# select * from Weather w1 inner join Weather w2 using(id) having w1.temperature>w2.temperature; 

select DISTINCT(w1.id) from Weather w1 
inner join Weather w2 
on w1.id!=w2.id where
w1.temperature>w2.temperature and 
DATE_ADD(w2.recordDate, INTERVAL 1 DAY)=w1.recordDate



