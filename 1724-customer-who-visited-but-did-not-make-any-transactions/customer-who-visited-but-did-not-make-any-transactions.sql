# Write your MySQL query statement below
# We will use left join so that all left table values are included, but non-existent values
# from right table will be given null
# We usually use group by with an aggregate function like :COUNT, SUM, AVG, MAX or MIN etc..
# What it basically does is that it groups rows sharing the same values in a somehow specified column or columns.

SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans
FROM Visits v LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id  IS NULL
GROUP BY v.customer_id