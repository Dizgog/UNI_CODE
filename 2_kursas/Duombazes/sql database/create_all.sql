-- Test if no objects exists before
\i test_exists.sql

-- Create Objects
\i create_tables.sql
\i create_index.sql
\i create_views.sql
\i create_mat_views.sql
\i create_triggers.sql

-- Insert Data
\i create_data.sql
\i update_mat_views.sql

-- Tests after
\i test_exists.sql
\i test_data.sql