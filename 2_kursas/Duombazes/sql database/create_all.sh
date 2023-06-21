#!/bin/sh

# Test if no objects exists before
psql -h pgsql3.mif -d studentu -f test_exists.sql

# Create Objects
psql -h pgsql3.mif -d studentu -f create_tables.sql
psql -h pgsql3.mif -d studentu -f create_index.sql
psql -h pgsql3.mif -d studentu -f create_views.sql
psql -h pgsql3.mif -d studentu -f create_mat_views.sql
psql -h pgsql3.mif -d studentu -f create_triggers.sql

# Insert Data
psql -h pgsql3.mif -d studentu -f create_data.sql
psql -h pgsql3.mif -d studentu -f update_mat_views.sql

# Tests after
psql -h pgsql3.mif -d studentu -f test_exists.sql
psql -h pgsql3.mif -d studentu -f test_data.sql