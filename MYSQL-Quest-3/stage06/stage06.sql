--
-- ETNA
--   JOUR 26 : EX 6
--

SELECT t.identifier AS 'type'
FROM pokemon AS p, types AS t, pokemon_types as pt
WHERE p.identifier = 'Scyther' AND pt.pokemon_id = p.id AND t.id = pt.type_id;