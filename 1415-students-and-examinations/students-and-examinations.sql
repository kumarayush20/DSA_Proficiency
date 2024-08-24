# Write your MySQL query statement below
# A cross join is a type of SQL join that returns the Cartesian product of the two tables involved. 
# This means that each row from the first table is combined with every row from the second table, resulting in a set of combinations of all rows.

SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) AS attended_exams
FROM Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;

# e.student_id: This refers to the student_id column in the Examinations table (e). 
# The Examinations table contains records of students who have attended exams for various subjects. 
# Since the query is counting the number of exams each student attended, 
# it makes sense to use e.student_id to perform the count, as this table is directly related to exam attendance.