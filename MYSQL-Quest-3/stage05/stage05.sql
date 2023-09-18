--
-- ETNA
--   JOUR 26 : EX 5
--

SELECT m.identifier AS 'attaque'
FROM moves AS m, pokemon AS p, pokemon_moves as pm
WHERE (p.identifier = 'Snorlax' AND pm.pokemon_id = p.id AND m.id = pm.move_id)
LIMIT 5;

-- SELECT moves.identifier AS 'attaque'
-- FROM moves INNER JOIN pokemon_moves ON moves.id = pokemon_moves.move_id
-- INNER JOIN pokemon ON pokemon.id = pokemon_moves.pokemon_id
-- WHERE pokemon.identifier = 'Snorlax'
-- LIMIT 5;