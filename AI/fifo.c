#include <stdlib.h>
#include <stdio.h>
#include "fifo.h"

queue * fifo_new()
{
	queue *fifo = malloc(sizeof(fifo));
	fifo->head = NULL;
	fifo->tail = NULL;
	fifo->count = 0;
	return fifo;
}

/* need to add function pointer to allow freeing data elements as well */
void fifo_free(queue * fifo)
{
	while (fifo->count > 0) {
		queue_item * item = fifo_remove(fifo);
		free(item);
	}
}

void fifo_add(queue * fifo, void * data)
{
	fifo->count = fifo->count + 1;

	queue_item *item = malloc(sizeof(item));
	item->prev = fifo->tail;
	item->next = NULL;
	item->data = data;

	if (fifo->tail != NULL) {
		(fifo->tail)->next = item;
	}

	if (fifo->head == NULL) {
		fifo->head = item;
	}

	fifo->tail = item;
}

void *fifo_remove(queue *fifo)
{
	void *data = NULL;

	if (fifo->count > 0) {
		fifo->count = fifo->count - 1;

		queue_item *item = fifo->head;
		queue_item *next = NULL;

		if (item != NULL)
		{
			data = item->data;
			next = item->next;
		}

		fifo->head = next;

		if (next != NULL)
		{
			next->prev = NULL;
		}

		free(item);
	}

	return data;
}
