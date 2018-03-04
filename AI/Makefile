CC = gcc
INCLUDE_FLAGS = -Iinclude -Iinclude/test
GCOV_FLAGS =  -fprofile-arcs -ftest-coverage
CFLAGS = -g -Wall -Werror -ansi -pedantic-errors -std=gnu99 -O0 $(INCLUDE_FLAGS) $(GCOV_FLAGS)

TEST_OBJS = \
src/test/test_ai_common.o src/ai_common.o \
src/test/test_fifo.o src/fifo.o \
src/test/test_graph.o src/graph.o 
#test_tree_search.o tree_search.o

all: test.exe

test: test.exe
	valgrind --leak-check=full ./test.exe

coverage: test
	gcov fifo.c graph.c ai_common.c
	lcov -c -d . --output-file=coverage.info
	genhtml -o ./html/ coverage.info

test.exe: src/test/test.o $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^	

.PHONY: clean
clean:
	rm -f *.exe \
	*.o */*.o */*/*.o \
	*/*.gcda */*/*.gcda \
	*/*.gcno */*/*.gcda \
	coverage.info

