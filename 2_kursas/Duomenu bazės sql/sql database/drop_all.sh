#!/bin/sh
psql -h pgsql3.mif -d studentu -f drop_triggers.sql
psql -h pgsql3.mif -d studentu -f drop_views.sql
psql -h pgsql3.mif -d studentu -f drop_index.sql
psql -h pgsql3.mif -d studentu -f drop_tables.sql

# Test if no objects exists after
psql -h pgsql3.mif -d studentu -f test_exists.sql