# Write your MySQL query statement below
SELECT p.product_id, IFNULL(ROUND(SUM(p.price*u.units)/sum(u.units), 2), 0) as average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
AND u.purchase_date BETWEEN p.Start_date AND p.end_date
GROUP BY p.product_id;

# Now as there can be null value for the average_price (as we are left joining tables) to handle these null values 
# (and replace null with a 0 in result table) we can use IFNULL() function as follows
# SELECT p.product_id, IFNULL(round(_____,2),0) as average_price