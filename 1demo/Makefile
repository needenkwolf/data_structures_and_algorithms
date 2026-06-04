CC = gcc
CFLAGS = -Wall -g -Wno-unused-variable

all: linkedlist/list.out linkedlist/polynomials/main.out array/demo.out \
	hashset/demo.out hashmap/demo.out stack/demo.out queue/demo.out \
	binarytree/demo.out

linkedlist/list.out: linkedlist/list.c $(wildcard ../linkedlist/*.c)
	$(CC) $(CFLAGS) $^ -o $@

linkedlist/polynomials/main.out: linkedlist/polynomials/main.c linkedlist/polynomials/polynomials.c $(wildcard ../linkedlist/*.c)
	$(CC) $(CFLAGS) $^ -o $@

array/demo.out: array/demo.c $(wildcard ../array/*.c) $(wildcard ../general/*.c)
	$(CC) $(CFLAGS) $^ -o $@

hashset/demo.out: hashset/demo.c $(wildcard ../hashset/*.c) $(wildcard ../array/*.c) $(wildcard ../general/*.c)
	$(CC) $(CFLAGS) $^ -o $@

hashmap/demo.out: hashmap/demo.c $(wildcard ../hashmap/*.c) $(wildcard ../array/*.c) $(wildcard ../general/*.c)
	$(CC) $(CFLAGS) $^ -o $@

stack/demo.out: stack/demo.c $(wildcard ../stack/*.c) $(wildcard ../linkedlist/*.c) $(wildcard ../general/*.c)
	$(CC) $(CFLAGS) $^ -o $@

queue/demo.out: queue/demo.c $(wildcard ../queue/*.c) $(wildcard ../linkedlist/*.c) $(wildcard ../general/*.c)
	$(CC) $(CFLAGS) $^ -o $@

binarytree/demo.out: binarytree/demo.c $(wildcard ../binarytree/*.c) $(wildcard ../general/*.c)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY:clean
clean: $(wildcard linkedlist/*.out) $(wildcard linkedlist/polynomials/*.out) $(wildcard array/*.out)
	rm $^
