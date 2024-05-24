
-- 코드를 작성해주세요


select count(1) as fish_count, max(length) as max_length, fish_type
from fish_info
where fish_type in (
    select fish_type
    from (
        select id, fish_type, length, time
        from fish_info
        where length >= 10
        union
        select id, fish_type, 10 as length, time
        from fish_info
        where length < 10
        or length is null
    ) as temp
    group by fish_type
    having avg(length) >= 33
)
group by fish_type
order by fish_type asc
        
