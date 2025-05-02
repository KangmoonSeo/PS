-- 코드를 입력하세요
SELECT MEMBER_NAME, REVIEW_TEXT, date_format(REVIEW_DATE, '%Y-%m-%d') as 'REVIEW_DATE'
from member_profile as m, rest_review as r
where m.member_id = r.member_id
and m.member_id = (
    select member_id from rest_review
    group by member_id
    order by count(1) desc
    limit 1
)
order by REVIEW_DATE asc, review_text asc