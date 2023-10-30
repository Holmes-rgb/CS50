-- select the people in Elena's Humanities class
SELECT people.name FROM courses
JOIN people ON roster.people_id=people.id
JOIN roster ON sections.id=roster.sections_id
JOIN sections ON courses.id=sections.courses_id
WHERE courses.name="Humanities" AND people.ROLE ='0'AND sections.period IN(
SELECT sections.period FROM courses
JOIN people ON roster.people_id=people.id
JOIN roster ON sections.id=roster.sections_id
JOIN sections ON courses.id=sections.courses_id
WHERE people.name="Elena" AND courses.name="Humanities") AND people.name IN(

--select the students in sebastian's Business management class
SELECT people.name FROM courses
JOIN people ON roster.people_id=people.id
JOIN roster ON sections.id=roster.sections_id
JOIN sections ON courses.id=sections.courses_id
WHERE courses.name="Business management" AND people.ROLE ='0'AND sections.period IN(
SELECT sections.period FROM courses
JOIN people ON roster.people_id=people.id
JOIN roster ON sections.id=roster.sections_id
JOIN sections ON courses.id=sections.courses_id
WHERE people.name="Sebastian" AND courses.name="Business management") AND people.name IN(

--find students in 5th period Computer programing
SELECT people.name FROM courses
JOIN people ON roster.people_id=people.id
JOIN roster ON sections.id=roster.sections_id
JOIN sections ON courses.id=sections.courses_id
WHERE courses.name="Computer programming" AND sections.period='5'AND people.ROLE ='0'));
