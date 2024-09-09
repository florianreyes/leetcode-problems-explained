-- Write a solution to calculate the number of bank accounts for each salary category. The salary categories are:

--     "Low Salary": All the salaries strictly less than $20000.
--     "Average Salary": All the salaries in the inclusive range [$20000, $50000].
--     "High Salary": All the salaries strictly greater than $50000.

-- The result table must contain all three categories. If there are no accounts in a category, return 0.

WITH accounts_with_tags as (SELECT
    a.account_id, 
    CASE
        WHEN a.income < 20000 THEN "Low Salary"
        WHEN a.income >= 20000 AND a.income <= 50000 THEN "Average Salary"
        ELSE "High Salary"
    END as bracket
    FROM Accounts a),
    brackets as (
        SELECT "Low Salary" as category
        UNION ALL
        SELECT "Average Salary"
        UNION ALL
        SELECT "High Salary"
    )
    SELECT category, count(at.account_id) as accounts_count
    FROM brackets b left join accounts_with_tags at on 
    b.category = at.bracket
    GROUP BY b.category
    ORDER BY accounts_count;