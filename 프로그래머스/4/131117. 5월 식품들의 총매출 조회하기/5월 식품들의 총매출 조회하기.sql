-- 코드를 입력하세요
SELECT p.PRODUCT_ID, product_name, price * sum(amount) as 'TOTAL_SALES'
from food_product as p, food_order as o
where p.product_id = o.product_id
and year(produce_date) = '2022'
and month(produce_date) = '5'
group by p.product_id, product_name, price
order by total_sales desc, p.product_id asc