CC=gcc

all: kockice test_kockice build

.PHONY: kockice test_kockice build

kockice:
	$(CC) -c src/kockice.c -o ../build/kockice.o

test_kockice:
	$(MAKE) -C test_kockice all

build:
	$(MAKE) -C build all
