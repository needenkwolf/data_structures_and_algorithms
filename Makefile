CC=gcc
CFLAGS=-Iinclude -shared -fPIC

libdatastrucs.so: $(wildcard array/*.c) $(wildcard linkedlist/*.c) $(wildcard hashmap/*.c) $(wildcard hashset/*.c) $(wildcard queue/*.c) $(wildcard stack/*.c) $(wildcard binarytree/*.c) $(wildcard general/*.c)
	$(CC) $(CFLAGS) $^ -o $@
