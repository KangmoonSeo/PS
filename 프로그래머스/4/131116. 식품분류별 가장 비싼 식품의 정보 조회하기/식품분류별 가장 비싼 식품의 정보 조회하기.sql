-- 코드를 입력하세요
SELECT category, price as max_price, product_name
from food_product
where (price, category) in (
    select max(price) as price, category 
    from food_product
    where category in ('과자', '국', '김치', '식용유')
    group by category
)
order by price desc