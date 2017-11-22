#ifndef _FIFO_H
#define _FIFO_H

typedef struct _queue_item queue_item;
struct _queue_item {
	queue_item *next;
	queue_item *prev;
	void *data;
};

typedef struct _queue queue;
struct _queue {
	queue_item *head;
	queue_item *tail;
	int count;
};

queue *fifo_new();
void fifo_free(queue *fifo);

void fifo_add(queue *fifo, void *data);
void *fifo_remove(queue *fifo);

#endif /* _FIFO_H */