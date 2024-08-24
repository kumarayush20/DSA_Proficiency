# Write your MySQL query statement below
SELECT 
    left(trans_date, 7) AS month, 
    country,
    COUNT(id) as trans_count,
    SUM(state='approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM((state='approved')*amount) AS approved_total_amount
FROM 
    Transactions
GROUP BY
    month, country;
