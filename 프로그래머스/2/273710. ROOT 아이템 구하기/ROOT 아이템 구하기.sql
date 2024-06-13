select i.ITEM_ID, i.item_name from item_info as i, item_tree as t
where t.parent_item_id is null
and i.item_id = t.item_id
order by i.item_id asc