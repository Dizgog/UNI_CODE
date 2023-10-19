CREATE MATERIALIZED VIEW noku8098.autoriaus_knygos
SELECT
    a.Pavadinimas,
    a.Metai,
    z.Pavadinimas,
    z.Zanras,
    z.Akcija
  FROM
    noku8098.Kompanija as a
  INNER JOIN
    noku8098.KompanijaZaidimas as v ON v.KompanijosID = a.NR
  INNER JOIN
    noku8098.Zaidimas as Z on z.NR = v.ZaidimoID
  GROUP BY
    a.Pavadinimas;
WITH NO DATA;