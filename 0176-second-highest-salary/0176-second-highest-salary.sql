SELECT MAX(salary) AS SecondHighestSalary
FROM (
    SELECT
        salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM
        Employee
) AS T
WHERE T.rnk = 2;