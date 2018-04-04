#ifndef _QUEUE_H
#define _QUEUE_H

enum QueueType {
	FirstInFirstOutQueue = 1,
	FirstInLastOutQueue = 2,
	PriorityQueue = 3
};

typedef struct _queue_item QueueItem;
struct _queue_item {
	QueueItem *next;
	void *data;
};

typedef struct _queue Queue;
struct _queue {
	int type;
	QueueItem *head;
	QueueItem *tail;
};

Queue *queue_new();
Queue *stack_new();
void queue_free(Queue *this);

int queue_has_items(Queue *this);
int queue_count_items(Queue *this);
void queue_add(Queue *this, void *data);
void *queue_remove(Queue *this);

#endif /* _QUEUE_H */