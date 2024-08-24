# Write your MySQL query statement below
Select 
    ROUND(AVG(order_date = customer_pref_delivery_date)*100, 2) as immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN (
  SELECT customer_id, min(order_date) 
  FROM Delivery
  GROUP BY customer_id
);

# WHERE (customer_id, order_date) IN (...): Filters the Delivery table to include only the earliest order for each customer. 
#This is done using the results from the subquery.

# AVG(order_date = customer_pref_delivery_date):

# order_date = customer_pref_delivery_date: This condition creates a boolean column where each row is TRUE if the order_date matches the customer_pref_delivery_date and FALSE otherwise.
# AVG(): The AVG() function calculates the average of this boolean column. In SQL, TRUE is treated as 1 and FALSE as 0, so AVG() will give the proportion of rows where order_date matches customer_pref_delivery_date.