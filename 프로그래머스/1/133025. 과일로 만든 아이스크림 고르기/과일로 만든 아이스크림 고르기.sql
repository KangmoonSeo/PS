-- 코드를 입력하세요
SELECT i.flavor as 'FLAVOR' from icecream_info as i, first_half as f
where i.ingredient_type = 'fruit_based'
and f.flavor = i.flavor
and f.total_order >= 3000
order by f.total_order desc