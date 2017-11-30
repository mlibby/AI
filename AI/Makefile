CFLAGS = -g -Wall -std=gnu99 -O1

common_obj = fifo.o graph.o romania.o sort.o common.o

all : 8puzzle.exe search_map.exe fifo_demo.exe graph_demo.exe sort_demo.exe

search_map.exe : search_map.o $(common_obj)
	cc -o $@ $< $(common_obj)

8puzzle.exe : 8puzzle.o $(common_obj)
	cc -o $@ $< $(common_obj)

fifo_demo.exe : fifo_demo.o $(common_obj)
	cc -o $@ $< $(common_obj)

graph_demo.exe: graph_demo.o $(common_obj)
	cc -o $@ $< $(common_obj)

sort_demo.exe: sort_demo.o $(common_obj)
	cc -o $@ $< $(common_obj)

8puzzle.o romania.o fifo_demo.o fifo.o : fifo.h common.h

graph.o: graph.h common.h

sort.o: common.h

.PHONY : clean
clean :
	rm -f $(common_obj) \
	search_map.exe seach_map.o \
	8puzzle.exe 8puzzle.o \
	fifo_demo.exe fifo_demo.o \
	graph_demo.exe graph_demo.o \
	sort_demo.exe sort_demo.o