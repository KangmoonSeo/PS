-- 코드를 입력하세요
SELECT u.USER_ID, u.NICKNAME, sum(b.price) as TOTAL_SALES from used_goods_user as u, used_goods_board as b
where u.user_id = b.writer_id
and b.status = 'done'
group by u.user_id
having sum(b.price) >= 700000
order by total_sales asc
-- 총금액 70만원 이상
-- 총거래금액 오름차순