--
-- ETNA
--   JOUR 26 : EX 12
--

select count(p.identifier) AS 'nb'
from pokemon AS p, types AS t, pokemon_types AS pt, pokemon_form_generations as pfg
where t.identifier = 'steel' AND pt.type_id = t.id AND p.id = pt.pokemon_id AND p.id = pfg.pokemon_form_id AND pfg.generation_id = 2;