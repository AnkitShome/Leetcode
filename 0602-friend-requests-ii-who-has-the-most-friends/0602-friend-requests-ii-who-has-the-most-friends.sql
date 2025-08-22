# Write your MySQL query statement below

with a as (
    select requester_id as id from RequestAccepted
    union all
    select accepter_id as id from RequestAccepted
)

select id, count(*) as num from a group by id order by count(*) desc limit 1