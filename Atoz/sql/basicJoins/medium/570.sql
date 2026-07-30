https://leetcode.com/problems/managers-with-at-least-5-direct-reports/

# Write your MySQL query statement below
SELECT m.name
FROM Employee m
JOIN Employee e
ON m.id = e.managerId
GROUP BY
    m.id,
    m.name
HAVING COUNT(*) >= 5