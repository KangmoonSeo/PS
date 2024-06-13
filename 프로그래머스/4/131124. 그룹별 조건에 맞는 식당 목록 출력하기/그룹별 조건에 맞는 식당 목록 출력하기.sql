select m.member_name, r.REVIEW_TEXT, date_format(r.REVIEW_DATE, "%Y-%m-%d") as review_date
    from rest_review as r,  member_profile as m
    where m.member_id = r.member_id
    and m.member_id = (
        SELECT MEMBER_ID FROM REST_REVIEW
    GROUP BY MEMBER_ID
    ORDER BY COUNT(*) DESC LIMIT 1
    )
order by review_date asc,
review_text asc