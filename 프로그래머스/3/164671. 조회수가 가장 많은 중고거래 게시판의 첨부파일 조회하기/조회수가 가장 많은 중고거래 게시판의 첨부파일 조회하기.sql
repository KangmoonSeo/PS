-- 코드를 입력하세요
SELECT concat("/home/grep/src/", b.board_id, "/", f.file_id, f.file_name, f.file_ext) 
as file_path
from used_goods_board as b, used_goods_file as f
where b.views in (
    SELECT max(views) as views
    FROM used_goods_board
)
and b.board_id = f.board_id
order by file_id desc