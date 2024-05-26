-- 코드를 입력하세요
SELECT b.book_id, a.author_name, date_format(b.published_date, "%Y-%m-%d")
from author as a, book as b
where a.author_id = b.author_id
and b.category = "경제"
order by b.published_date asc