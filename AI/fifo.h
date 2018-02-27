#include "common.h"

#ifndef _FIFO_H
#define _FIFO_H

typedef struct _fifo_item fifo_item;
struct _fifo_item {
	fifo_item *next;
	void *data;
};

typedef struct _fifo fifo;
struct _fifo {
	fifo_item *head;
	fifo_item *tail;
};

fifo *fifo_new();
void fifo_free(fifo *this);

int fifo_has_items(fifo *this);
void fifo_add(fifo *this, void *data);
void *fifo_remove(fifo *this);

#endif /* _FIFO_H */