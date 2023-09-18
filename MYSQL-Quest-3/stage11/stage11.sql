--
-- ETNA
--   JOUR 26 : EX 11
--

SELECT AVG(weight) AS Moyenne
FROM pokemon
WHERE identifier IN ('Suicune', 'Entei', 'Raikou');