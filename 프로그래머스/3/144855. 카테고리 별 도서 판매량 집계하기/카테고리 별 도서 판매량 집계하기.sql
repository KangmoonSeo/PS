select category, sum(sales) as total_sales from book as b, book_sales as s
where b.book_id = s.book_id
and sales_date like '2022-01%'
group by category
order by category asc