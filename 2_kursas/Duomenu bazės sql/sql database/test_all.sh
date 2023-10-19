#!/bin/sh
psql -h pgsql3.mif -d studentu -f test_exists.sql
psql -h pgsql3.mif -d studentu -f test_data.sql
psql -h pgsql3.mif -d studentu -f test_index.sql
psql -h pgsql3.mif -d studentu -f test_keys.sql
psql -h pgsql3.mif -d studentu -f test_constraints.sql
psql -h pgsql3.mif -d studentu -f test_triggers.sql