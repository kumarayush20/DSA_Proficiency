# Write your MySQL query statement below
SELECT e.name, b.bonus FROM
Employee e LEFT JOIN Bonus b
ON e.empID = b.empId
WHERE b.bonus < 1000 or b.bonus IS NULL; 

# Left join cuz right wala can be null, take IS NULL too