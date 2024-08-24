# Write your MySQL query statement below
SELECT
  ROUND(COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM
  Activity
WHERE
  (player_id, DATE_SUB(event_date, INTERVAL 1 DAY))
  IN (
    SELECT player_id, MIN(event_date) AS first_login FROM Activity GROUP BY player_id
  );

# DATE_SUB(event_date, INTERVAL 1 DAY): This expression subtracts one day from the event_date, resulting in a date one day before the current event_date.
# The WHERE clause ensures that only rows where the adjusted date (DATE_SUB(event_date, INTERVAL 1 DAY)) matches the earliest login date for that player_id are considered. 
# Essentially, it selects records where the event_date is the day after the player’s first login date.

# (SELECT COUNT(DISTINCT player_id) FROM Activity):
# This subquery calculates the total number of unique player_id values in the entire Activity table.