 SELECT user_id, product_id from online_sale
 where online_sale_id in (
  select online_sale_id from online_sale
    group by user_id, product_id
    having count(*) >= 2
 )

 order by user_id asc, product_id desc
