--== isoriniu raktu ribojimu patikra ==
-- neegzistuojantis Vartotojas
INSERT INTO noku8098.Biblioteka VALUES(1, 2, 59.99, 3, 2015);
-- neegzistuojanti Zaidimas
INSERT INTO noku8098.Biblioteka VALUES(1, 4, 59.99, 1, 2016);
INSERT INTO noku8098.KompanijaZaidimas VALUES(1, 4) ;
-- neegzistuojantis Kompanija
INSERT INTO kuosis.KompanijaZaidimas VALUES(5,  1) ;
-- update restrict'ai
UPDATE noku8098.Zaidimas SET Nr = 4 WHERE ISBN = 1;
UPDATE noku8098.Kompanija SET NR = 5 WHERE nr = 2;
UPDATE noku8098.vartotojas SET ID = 5 where ID = 1;

-- delete cascade'ai
-- KompanijaZaidimas -> Zaidimas delete cascade'o patikra
---- Prepare
INSERT INTO noku8098.Zaidimas VALUES(6, 'Read dead redemption 2', 'Action', 2018, 0, 59.99) ;
INSERT INTO noku8098.KompanijaZaidimas VALUES(2,  6) ;
SELECT * FROM noku8098.Zaidimas WHERE Nr = 6;
SELECT * FROM noku8098.KompanijaZaidimas WHERE ZaidimoID = 6;
---- Delete
DELETE FROM noku8098.Zaidimas WHERE Nr = 6;
---- Check
SELECT * FROM noku8098.Zaidimas WHERE Nr = 6;
SELECT * FROM noku8098.KompanijaZaidimas WHERE ZaidimoID = 6;

-- KompanijaZaidimas -> Kompanija delete cascade'o patikra
---- Prepare
INSERT INTO noku8098.Kompanija VALUES (4, 'Activision', 2);
INSERT INTO noku8098.KompanijaZaidimas VALUES(4,  5) ;
SELECT * FROM noku8098.Kompanija WHERE Nr = 4;
SELECT * FROM noku8098.KompanijaZaidimas WHERE KompanijosID = 4;
---- Delete
DELETE FROM noku8098.Kompanija WHERE Nr = 4;
---- Check
SELECT * FROM noku8098.Kompanija WHERE Nr = 4;
SELECT * FROM noku8098.KompanijaZaidimas WHERE KompanijosID = 4;

-- Biblioteka -> Zaidimas delete cascade'o patikra
---- Prepare
INSERT INTO noku8098.Zaidimas VALUES(6, 'Read dead redemption 2', 'Action', 2018, 0, 59.99) ;
INSERT INTO noku8098.Biblioteka VALUES(5, 6, 59.99, 1, 2019) ;
SELECT * FROM noku8098.Zaidimas WHERE Nr = 6;
SELECT * FROM noku8098.Biblioteka WHERE Zaidimas = 6;
---- Delete
DELETE FROM noku8098.Zaidimas WHERE Nr = 6;;
---- Check
SELECT * FROM noku8098.Zaidimas WHERE Nr = 6;
SELECT * FROM noku8098.Biblioteka WHERE Zaidimas = 6;

-- Biblioteka -> Vartotojas delete set null'o patikra
INSERT INTO noku8098.Vartotojas VALUES(6, 'Pioter', '666666') ;
INSERT INTO noku8098.Biblioteka values(5, 4, 39.99, 6, 2016)
SELECT * FROM noku8098.Vartotojas WHERE ID = 6;
SELECT * FROM kuosis.Egzempliorius WHERE ID = 5;
---- Delete
DELETE FROM noku8098.Vartotojas WHERE ID = 6;
---- Check
SELECT * FROM noku8098.Vartotojas WHERE ID = 6;
SELECT * FROM kuosis.Egzempliorius WHERE ID = 5;