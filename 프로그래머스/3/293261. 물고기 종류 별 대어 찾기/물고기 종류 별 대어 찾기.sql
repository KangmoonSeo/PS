select i.id as 'ID', n.fish_name as 'FISH_NAME', i.length as 'LENGTH' 
from fish_info as i, fish_name_info as n
where i.fish_type = n.fish_type
and (i.fish_type, length) in (
  select fish_type, max(length)
    from fish_info
    group by fish_type
)

order by i.id asc