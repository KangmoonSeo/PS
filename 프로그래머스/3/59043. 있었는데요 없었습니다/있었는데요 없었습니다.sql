-- 코드를 입력하세요
SELECT i.animal_id as 'ANIMAL_ID', i.name as 'NAME'
from animal_ins as i, animal_outs as o
where i.animal_id = o.animal_id
and i.datetime > o.datetime
order by i.datetime asc