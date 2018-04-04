CC = gcc
INCLUDE_FLAGS = -Iinclude -Iinclude/test
GCOV_FLAGS =  -fprofile-arcs -ftest-coverage
STD_FLAGS = -ansi -std=gnu99 -D_POSIX_C_SOURCE=200809L
CFLAGS = -g -O0 -Wall -Werror $(STD_FLAGS) $(INCLUDE_FLAGS) $(GCOV_FLAGS)

MODULES = \
agent \
ai_common \
breadth_search \
environment \
graph \
queue \
search_node \
simulator

SRC := $(addprefix src/, $(addsuffix .c, $(MODULES)))
OBJS := $(SRC:.c=.o)
TEST_OBJS := $(addprefix src/test/test_, $(addsuffix .o, $(MODULES)))

all: test.exe

echo: 
	echo SRC = $(SRC)
	echo OBJS = $(OBJS)
	echo TEST_OBJS = $(TEST_OBJS)

search_romania.exe: src/search_romania.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^	

test: test.exe
	./test.exe

grind: test.exe
	valgrind --leak-check=full ./test.exe


coverage: test
	gcov $(SRC)
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