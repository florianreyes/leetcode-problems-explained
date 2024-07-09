-- The idea is to select the employees who are in the primary department or who are the only employee in their department.
-- The primary department is the department where the employee has the primary_flag set to 'Y'.


SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y' OR employee_id in (
    select employee_id from Employee
    GROUP BY employee_id
    HAVING COUNT(*) = 1
);