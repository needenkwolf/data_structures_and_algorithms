CC = gcc
CFLAGS = -Wall -g

all: list.out polynomials.out

list.out: list.c $(wildcard ../*.c)
	$(CC) $(CFLAGS) $^ -o $@

polynomials.out: polynomials.c $(wildcard ../*.c)
	$(CC) $(CFLAGS) $^ -o $@


.PHONY:clean
clean: $(wildcard *.out)
	rm $^
