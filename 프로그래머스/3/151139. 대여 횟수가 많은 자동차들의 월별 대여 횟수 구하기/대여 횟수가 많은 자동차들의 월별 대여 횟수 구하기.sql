-- 코드를 입력하세요
SELECT month(start_date) as month, car_id, count(1) as records
from CAR_RENTAL_COMPANY_RENTAL_HISTORY

where start_date between '2022-08-01' and '2022-10-31'
and car_id in (
    select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date between '2022-08-01' and '2022-10-31'
    group by car_id
    having count(1) >= 5

)
group by month, car_id
having records > 0
order by month asc, car_id desc
