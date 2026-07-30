https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

# Write your MySQL query statement below
SELECT eu.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI eu
ON e.id = eu.id;