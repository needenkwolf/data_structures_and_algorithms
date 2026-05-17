CC = gcc
CFLAGS = -Wall
OUTPUT = list.out

$(OUTPUT): $(wildcard *.c)
	$(CC) $^ $(CFILES) -o $@

.PHONY:clean
clean:
	rm $(OUTPUT)
