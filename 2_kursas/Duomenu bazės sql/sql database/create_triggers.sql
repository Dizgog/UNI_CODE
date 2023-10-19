CREATE FUNCTION noku8098.Kompanijos_Check()
  RETURNS trigger
  LANGUAGE plpgsql
  AS
$$
BEGIN
    IF NEW.Vardas = 'Nezinoma' THEN
        RAISE EXCEPTION 'Kompanija negali būti Nezinoma';
    END IF;

    RETURN NEW;
END;
$$

CREATE TRIGGER Kompanijos_Check1 BEFORE INSERT OR UPDATE ON noku8098.Kompanija
    FOR EACH ROW EXECUTE FUNCTION noku8098.Kompanijos_Check();

CREATE OR REPLACE FUNCTION noku8098.Vartotojo_Check()
    RETURNS trigger
    AS
$$
BEGIN
    IF ((NEW.Slaptazodis IS NULL) AND (NEW.Slapyvardis IS NOT NULL)) THEN
      RAISE EXCEPTION 'Kiekveinas vartotojas turi turėti slaptažodi';
    END IF;

    RETURN NEW;
END;
$$

CREATE TRIGGER Vartotojo_Check1 BEFORE INSERT OR UPDATE ON noku8098.Vartotojas
    FOR EACH ROW EXECUTE FUNCTION noku8098.Vartotojo_Check();