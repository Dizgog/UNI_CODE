CREATE VIEW noku8098.Action_Zanras
AS
  SELECT
     *
  FROM
     noku8098.Zaidimas
  WHERE
     Zanras = 'Action';

CREATE VIEW noku8098.Kureju_Info
AS
  SELECT
    a.Pavadinimas,
    a.Metai,
    COUNT(*) as Isleisti_Zaidimai
  FROM
    noku8098.Kompanija as a
  INNER JOIN
    noku8098.KompanijaZaidimas as v ON v.KompanijosID = a.NR
  INNER JOIN
    noku8098.Zaidimas as Z on z.NR = v.ZaidimoID
  GROUP BY
    a.Pavadinimas;