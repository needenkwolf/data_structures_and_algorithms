CC = gcc
CFLAGS = -Wall -g

all: list.out polynomials/main.out

list.out: list.c $(wildcard ../*.c)
	$(CC) $(CFLAGS) $^ -o $@

polynomials/main.out: polynomials/main.c polynomials/polynomials.c $(wildcard ../*.c)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:clean
clean: $(wildcard *.out)
	rm $^
