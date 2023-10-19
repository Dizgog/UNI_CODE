SELECT table_schema, table_name, table_type FROM INFORMATION_SCHEMA.tables WHERE table_schema = 'noku8098';
SELECT table_schema, table_name, constraint_name FROM INFORMATION_SCHEMA.Key_column_usage WHERE table_schema = 'noku8098';
SELECT * FROM INFORMATION_SCHEMA.triggers WHERE trigger_schema = 'noku8098';