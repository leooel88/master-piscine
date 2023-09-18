--
-- ETNA
--   JOUR 26 : EX 20
--

SELECT t.id AS 'type_id', COUNT(pt.pokemon_id) AS 'nb'
FROM types AS t, pokemon_types AS pt
WHERE t.id = pt.type_id
GROUP BY (t.id);