CFLAGS = -g -Wall -std=gnu99 -O3

common_obj = fifo.o

all : 8puzzle.exe romania.exe fifo_demo.exe

romania.exe : romania.o $(common_obj)
	cc -o $@ $< $(common_obj)

8puzzle.exe : 8puzzle.o $(common_obj)
	cc -o $@ $< $(common_obj)

fifo_demo.exe : fifo_demo.o $(common_obj)
	cc -o $@ $< $(common_obj)

8puzzle.o romania.o fifo_demo.o fifo.o : fifo.h

.PHONY : clean
clean :
	rm -f $(common_obj) \
	romania.exe romania.o \
	8puzzle.exe 8puzzle.o \
	fifo_demo.exe fifo_demo.o