-- 코드를 작성해주세요

select count(1) as fish_count, month(time) as month
from fish_info
group by month
having month > 0
order by month asc