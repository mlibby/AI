CC = gcc
CFLAGS = -g -Wall -Werror -ansi -pedantic-errors -std=gnu99 -O0

TEST_OBJS = \
test_fifo.o fifo.o \
test_graph.o graph.o \
test_sort.o sort.o

all: test.exe

test.exe: test.o $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^	

.PHONY: clean
clean:
	rm -f *.exe *.o 

