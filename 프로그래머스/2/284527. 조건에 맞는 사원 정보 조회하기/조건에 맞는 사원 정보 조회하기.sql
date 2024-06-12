select sum(g.score) as score, e.emp_no, e.emp_name, e.position, e.email from hr_department as d, hr_employees as e, hr_grade as g

where d.dept_id = e.dept_id
and g.emp_no = e.emp_no
group by e.emp_no
order by score desc
limit 1
