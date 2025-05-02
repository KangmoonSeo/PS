select distinct ID, EMAIL, FIRST_NAME, LAST_NAME from developers as d, skillcodes as s
where d.skill_code & s.code = s.code
and category = 'Front End'
order by id asc