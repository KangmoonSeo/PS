-- 코드를 입력하세요
-- SELECT USER_ID, PRODUCT_ID from ONLINE_SALE
-- order by USER_ID asc, PRODUCT_ID desc



select user_id, product_id
from ONLINE_SALE
group by user_id, product_id
having count(*) >= 2
order by user_id asc, product_id desc