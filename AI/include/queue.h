#ifndef _QUEUE_H
#define _QUEUE_H

enum QueueType {
	FirstInFirstOutQueue = 1,
	FirstInLastOutQueue = 2,
	PriorityQueue = 3
};

typedef struct _queue_item queue_item;
struct _queue_item {
	queue_item *next;
	void *data;
};

typedef struct _queue queue;
struct _queue {
	int type;
	queue_item *head;
	queue_item *tail;
};

queue *queue_new();
queue *stack_new();
void queue_free(queue *this);

int queue_has_items(queue *this);
void queue_add(queue *this, void *data);
void *queue_remove(queue *this);

#endif /* _QUEUE_H */