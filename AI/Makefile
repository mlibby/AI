CC = gcc
CFLAGS = -g -Wall -std=gnu99 -O0

common_obj = tree_search.o search_node.o fifo.o graph.o roadmap.o sort.o common.o

all : 8puzzle.exe search_map.exe fifo_demo.exe sort_demo.exe graph_demo.exe roadmap_demo.exe

search_map.exe : search_map.o $(common_obj)
	$(CC) $(CFLAGS) -o $@ $< $(common_obj)

8puzzle.exe : 8puzzle.o $(common_obj)
	$(CC) $(CFLAGS) -o $@ $< $(common_obj)

fifo_demo.exe : fifo_demo.o $(common_obj)
	$(CC) $(CFLAGS) -o $@ $< $(common_obj)

graph_demo.exe: graph_demo.o $(common_obj)
	$(CC) $(CFLAGS) -o $@ $< $(common_obj)

sort_demo.exe: sort_demo.o $(common_obj)
	$(CC) $(CFLAGS) -o $@ $< $(common_obj)

roadmap_demo.exe: roadmap_demo.o $(common_obj)
	$(CC) $(CFLAGS) -o $@ $< $(common_obj)

8puzzle.o search_node.o fifo.o: fifo.h common.h

roadmap.o: roadmap.h graph.h common.h

graph.o: graph.h common.h

tree_search.o: tree_search.h search_node.h graph.h fifo.h common.h

sort.o: common.h

.PHONY : clean
clean :
	rm -f $(common_obj) \
	search_map.exe seach_map.o \
	8puzzle.exe 8puzzle.o \
	fifo_demo.exe fifo_demo.o \
	graph_demo.exe graph_demo.o \
	sort_demo.exe sort_demo.o \
	roadmap_demo.exe roadmap_demo.o