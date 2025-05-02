-- 코드를 입력하세요
SELECT product_code, price * sum(sales_amount) as 'SALES' from product as p, offline_sale as o
where p.product_id = o.product_id
group by product_code, price
order by sales desc, product_code asc