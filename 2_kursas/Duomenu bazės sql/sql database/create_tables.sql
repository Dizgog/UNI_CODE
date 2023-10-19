CREATE TABLE noku8098.Zaidimas (
    Nr SERIAL NOT NULL,
    Pavadinimas VARCHAR(32) NOT NULL,
    Zanras CHAR(12) NOT NULL,
    Metai SMALLINT NOT NULL CONSTRAINT LeidimoMetai CHECK(
        Metai > 1900
        AND Metai < EXTRACT(
            YEAR
            FROM
                CURRENT_DATE
        ) + 1
    ),
    Akcija SMALLINT NOT NULL CONSTRAINT ZaidimoAkcija CHECK(
        Akcija >= 0
        AND akcija <= 100
    ),
    Verte DECIMAL(5, 2) DEFAULT 15 CONSTRAINT VertesDydis CHECK(
        Verte >= 0
        AND Verte <= 1000
    ),
    PRIMARY KEY (Nr),
    CONSTRAINT FKKompanija FOREIGN KEY (Nr) REFERENCES noku8098.Kompanija ON DELETE CASCADE ON UPDATE RESTRICT
);

CREATE TABLE noku8098.Kompanija (
    NR SERIAL NOT NULL,
    Vardas CHAR(12) NOT NULL,
    Salies_ID SMALLINT NOT NULL,
    PRIMARY KEY (NR),
    CONSTRAINT ISalis FOREIGN KEY (Salies_ID) REFERENCES noku8098.Salis ON DELETE CASCADE ON UPDATE RESTRICT,
);

CREATE TABLE noku8098.Vartotojas (
    ID SERIAL NOT NULL,
    Slapyvardis CHAR(12) NOT NULL,
    Slaptazodis VARCHAR(20) NOT NULL,
    PRIMARY KEY (ID)
);

CREATE TABLE noku8098.Biblioteka (
    ID SERIAL NOT NULL,
    Zaidimas INTEGER NOT NULL,
    Kaina DECIMAL(5, 2) DEFAULT 15 CONSTRAINT ZaidimoKaina CHECK(
        Kaina >= 0
        AND Kaina <= 1000
    ),
    Vartotojas INTEGER NOT NULL,
    Nusipirkta SMALLINT NOT NULL,
    PRIMARY KEY (ID),
    CONSTRAINT IZaidimas FOREIGN KEY (Zaidimas) REFERENCES noku8098.Zaidimas ON DELETE CASCADE ON UPDATE RESTRICT,
    CONSTRAINT IVartotojas FOREIGN KEY (Vartotojas) REFERENCES noku8098.Vartotojas ON DELETE CASCADE ON UPDATE RESTRICT,
);

CREATE TABLE noku8098.Salis (
    Salies_ID SERIAL NOT NULL,
    Salis CHAR(12) NOT NULL,
    PRIMARY KEY (Salies_ID)
);

CREATE TABLE noku8098.KompanijaZaidimas (
    KompanijosID SERIAL NOT NULL,
    ZaidimoID SERIAL NOT NULL,
    PRIMARY KEY (KompanijosID, ZaidimoID),
    CONSTRAINT TKompanija FOREIGN KEY (KompanijosID) REFERENCES noku8098.Kompanija ON DELETE CASCADE ON UPDATE RESTRICT,
    CONSTRAINT TZaidima FOREIGN KEY (ZaidimoID) REFERENCES noku8098.Zaidimas ON DELETE CASCADE ON UPDATE RESTRICT
)