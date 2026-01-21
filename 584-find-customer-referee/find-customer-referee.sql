# Write your MySQL query statement below
# any id that is not 2 and not referred by any customer
select name from customer
where referee_id is NULL or referee_id != 2;