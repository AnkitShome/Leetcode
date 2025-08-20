SELECT person_name
FROM (
    SELECT person_name,
           turn,
           SUM(weight) OVER (ORDER BY turn) AS running_weight
    FROM Queue
) AS sub
WHERE running_weight <= 1000
ORDER BY turn DESC
LIMIT 1;
