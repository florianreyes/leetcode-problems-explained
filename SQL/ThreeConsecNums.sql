-- The idea is to find the numbers that are consecutive in the Logs table.
-- You have to find three consecutive numbers that are equall, and their id is consecutive.

SELECT DISTINCT(num) AS ConsecutiveNums 
FROM(
    SELECT id, num,
    LAG(num) OVER (ORDER BY id) as prev,
    LEAD(num) OVER (ORDER BY id) as next
    FROM Logs
) next_prev
WHERE prev = num AND prev = next;
