-- We want to see who is a manager and how many people they have in their team.
-- We also want to see the average age of the people in their team.
-- The result should be ordered by the manager's ID.
-- We make a self join where the employees report_to is equal to the employee id, meaning that the employee is a manager.

SELECT man.employee_id, man.name, COUNT(emp.employee_id) as reports_count, ROUND(AVG(emp.age)) as average_age
FROM Employees man, Employees emp
WHERE emp.reports_to = man.employee_id
GROUP BY man.employee_id
ORDER BY man.employee_id;



select t1.employee_id,t1.name,count(t2.employee_id) as reports_count,round(avg(t2.age)) as average_age
from employees t1 join employees t2 on t1.employee_id=t2.reports_to
group by t1.employee_id 
order by t1.employee_id