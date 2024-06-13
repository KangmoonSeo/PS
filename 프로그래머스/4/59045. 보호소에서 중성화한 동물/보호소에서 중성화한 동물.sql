-- 코드를 입력하세요
SELECT ANIMAL_ID, ANIMAL_TYPE, NAME from animal_outs
where sex_upon_outcome like '%ed%'
and animal_id in (
    select animal_id from animal_ins
where sex_upon_intake like '%intact%'
)