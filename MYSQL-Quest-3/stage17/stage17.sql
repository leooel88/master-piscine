--
-- ETNA
--   JOUR 26 : EX 17
--

SELECT COUNT(p.identifier) AS 'nb'
FROM pokemon AS p, pokemon_form_generations AS pfg
WHERE p.id = pfg.pokemon_form_id AND pfg.generation_id = 6;