select author_id, author_name, category, sum(total_sales) as total_sales
from (
select a.author_id, a.author_name, b.book_id, b.category, sum(b.price * s.sales) as total_sales
from author as a, book as b, book_sales as s
where b.book_id = s.book_id
and a.author_id = b.author_id
and s.sales_date like "2022-01%"
group by b.book_id
) temp
group by author_name, category
order by author_id asc, category desc

