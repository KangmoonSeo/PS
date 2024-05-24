select flavor
from
(
select flavor, sum(total_order) as tot
from (
select flavor, total_order
from first_half
union 
select flavor, total_order
from july
) temp
group by flavor
order by tot desc
limit 3
) t2