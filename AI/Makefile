CC = gcc
INCLUDE_FLAGS = -Iinclude -Iinclude/test
GCOV_FLAGS =  -fprofile-arcs -ftest-coverage
CFLAGS = -g -Wall -Werror -ansi -pedantic-errors -std=gnu99 -O0 $(INCLUDE_FLAGS) $(GCOV_FLAGS)

OBJS = \
src/ai_common.o \
src/graph.o \
src/queue.o \
src/search_node.o \
src/breadth_search.o

TEST_OBJS = \
src/test/test_ai_common.o \
src/test/test_graph.o \
src/test/test_queue.o \
src/test/test_search_node.o \
src/test/test_breadth_search.o 
all: test.exe

search_romania.exe: src/search_romania.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^	

test: test.exe
	valgrind --leak-check=full ./test.exe

coverage: test
	gcov src/ai_common.c src/graph.c src/queue.c src/search_node.c src/breadth_search.c
	lcov -c -d . --output-file=coverage.info
	genhtml -o ./html/ coverage.info

test.exe: src/test/test.o $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^	

.PHONY: clean
clean:
	rm -f *.exe \
	*.o */*.o */*/*.o \
	*/*.gcda */*/*.gcda \
	*/*.gcno */*/*.gcno \
	coverage.info