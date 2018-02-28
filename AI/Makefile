CC = gcc
CFLAGS = -g -Wall -Werror -ansi -pedantic-errors -std=gnu99 -O0

all: test.exe

test.exe: test.o test_fifo.o fifo.o test_graph.o graph.o
	$(CC) $(CFLAGS) -o $@ $^	

.PHONY: clean
clean:
	rm -f *.exe *.o 

