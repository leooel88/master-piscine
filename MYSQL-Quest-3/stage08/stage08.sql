--
-- ETNA
--   JOUR 26 : EX 8
--

SELECT s.identifier AS 'nom_stat', ps.base_stat AS 'nb'
FROM pokemon AS p, pokemon_stats AS ps, stats AS s
WHERE p.identifier = 'Mewtwo' AND ps.pokemon_id = p.id AND s.id = ps.stat_id;