--
-- ETNA
--   JOUR 26 : EX 7
--

SELECT COUNT(p.id) AS 'nb'
FROM pokemon AS p, types AS t, pokemon_types AS pt
WHERE t.identifier = 'ice' AND pt.type_id = t.id AND p.id = pt.pokemon_id;