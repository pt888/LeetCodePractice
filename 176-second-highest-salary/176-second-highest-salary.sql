# Write your MySQL query statement below
# select max(salary) as SecondHighestSalary from employee where salary not in (select max(salary) from employee)
# select salary from employee where salary in 


# Select ifnull(
#     (SELECT distinct salary as SecondHighestSalary from Employee order by salary desc limit 1 offset 1)
#     ,null)
#     as SecondHighestSalary;
    
    
Select ifnull((SELECT distinct salary as SecondHighestSalary from Employee order by salary desc limit 1 offset 1),null) as SecondHighestSalary;