CC=gcc

all: listic test_listic build

.PHONY: listic test_listic build

listic:
	$(CC) -c src/listic.c -o ../build/listic.o

test_listic:
	$(MAKE) -C test_listic all

build:
	$(MAKE) -C build all
