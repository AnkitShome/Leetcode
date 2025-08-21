# Write your MySQL query statement below

select s1.id,s2.student from Seat s1 join Seat s2 on s1.id = case
when s1.id%2=1 then s2.id-1
else s2.id+1
end
union all
select s.id,s.student from Seat s where s.id=(select max(id) from Seat) and (select count(*) from Seat) % 2=1

order by id