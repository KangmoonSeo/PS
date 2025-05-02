-- 코드를 입력하세요
SELECT book_id, author_name, date_format(published_date, '%Y-%m-%d') as 'published_date' from author as a, book as b
where a.author_id = b.author_id
and category = '경제'

order by published_date asc