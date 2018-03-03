CC = gcc
CFLAGS = -g -Wall -Werror -ansi -pedantic-errors -std=gnu99 -O0 -fprofile-arcs -ftest-coverage

TEST_OBJS = \
test_fifo.o fifo.o \
test_graph.o graph.o \
test_ai_common.o ai_common.o

all: test.exe

test: test.exe
	valgrind --leak-check=full ./test.exe

coverage: test
	gcov fifo.c graph.c ai_common.o
	lcov -c -d . --output-file=coverage.info
	genhtml -o ./html/ coverage.info

test.exe: test.o $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^	

.PHONY: clean
clean:
	rm -f *.exe *.o 

