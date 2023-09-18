--
-- ETNA
--   JOUR 26 : EX 10
--

SELECT eg.identifier AS 'TypeOeuf'
FROM egg_groups AS eg, pokemon AS p, pokemon_egg_groups AS peg
WHERE p.identifier = 'Noctowl' AND peg.species_id = p.species_id AND eg.id = peg.egg_group_id;