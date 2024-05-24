-- 코드를 입력하세요
SELECT c.car_id, c.car_type, round(c.daily_fee * (100 - p.discount_rate) * 0.3) as fee from
CAR_RENTAL_COMPANY_CAR as c,
CAR_RENTAL_COMPANY_DISCOUNT_PLAN as p
where c.car_type = p.car_type
and c.car_id not in (
    select distinct car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date <= "2022-11-30"
    and end_date >= "2022-11-01"
    )
and p.duration_type = "30일 이상"
and c.daily_fee * (100 - p.discount_rate) * 0.3 between 500000 and 2000000
order by fee desc, car_type asc, car_id desc