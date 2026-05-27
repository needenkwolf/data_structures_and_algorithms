CC = gcc
CFLAGS = -Wall -g

all: linkedlist/list.out linkedlist/polynomials/main.out array/demo.out

linkedlist/list.out: linkedlist/list.c $(wildcard ../linkedlist/*.c)
	$(CC) $(CFLAGS) $^ -o $@

linkedlist/polynomials/main.out: linkedlist/polynomials/main.c linkedlist/polynomials/polynomials.c $(wildcard ../linkedlist/*.c)
	$(CC) $(CFLAGS) $^ -o $@

array/demo.out: array/demo.c $(wildcard ../array/*.c)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:clean
clean: $(wildcard linkedlist/*.out) $(wildcard linkedlist/polynomials/*.out) $(wildcard array/*.out)
	rm $^
