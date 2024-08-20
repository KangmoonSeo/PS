-- 코드를 입력하세요
SELECT distinct u.USER_ID, u.nickname, 
concat(u.city, ' ', u.street_address1, ' ', u.street_address2) as 전체주소, 
concat(substr(u.tlno, 1, 3), '-', substr(u.tlno, 4, 4), '-', substr(u.tlno, 8, 4)) as 전화번호 
from used_goods_board b, used_goods_user u
where b.writer_id = u.user_id
and b.writer_id in (
select writer_id from used_goods_board
    group by writer_id
    having count(*) >= 3
)
order by u.user_id desc