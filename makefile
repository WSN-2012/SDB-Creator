CC=gcc
LIBS=-lsqlite3

create_test_sdb: create_test_sdb.c
	gcc -o $@ $^ $(LIBS)



