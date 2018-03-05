CC = gcc
INCLUDE_FLAGS = -Iinclude -Iinclude/test
GCOV_FLAGS =  -fprofile-arcs -ftest-coverage
CFLAGS = -g -Wall -Werror -ansi -pedantic-errors -std=gnu99 -O0 $(INCLUDE_FLAGS) $(GCOV_FLAGS)

TEST_OBJS = \
src/test/test_ai_common.o src/ai_common.o \
src/test/test_fifo.o src/fifo.o \
src/test/test_graph.o src/graph.o \
src/test/test_lifo.o src/lifo.o \
src/test/test_search_node.o src/search_node.o \
src/test/test_tree_search.o src/tree_search.o

all: test.exe

test: test.exe
	valgrind --leak-check=full ./test.exe

coverage: test
	gcov src/ai_common.c src/fifo.c src/graph.c src/lifo.c src/search_node.c src/tree_search.c
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

