#include <stdlib.h>
#include "ai_common.h"
#include "queue.h"

Queue
*queue_new()
{
	Queue *this = malloc(sizeof(Queue));
	this->type = FirstInFirstOutQueue;
	this->head = NULL;
	this->tail = NULL;
	return this;
}

Queue
*stack_new()
{
	Queue *this = queue_new();
	this->type = FirstInLastOutQueue;
	return this;
}

void
queue_free(Queue *this)
{
	while (queue_has_items(this)) {
		queue_remove(this);
	}
	free(this);
}

int
queue_count_items(Queue *this)
{
	int count = 0;
	QueueItem *item = this->head;
	while (item) {
		count++;
		item = item->next;
	}
	return count;
}

int
queue_has_items(Queue *this)
{
	return this->head != NULL;
}

void
fifo_add(Queue *this, void *data)
{
	QueueItem *item = malloc(sizeof(QueueItem)); 
	item->next = NULL;
	item->data = data;

	if (this->head == NULL) {
		this->head = item;
	}

	if (this->tail != NULL) {
		(this->tail)->next = item;
	}
	  
	this->tail = item;
}

void
lifo_add(Queue *this, void *data)
{
	QueueItem *item = malloc(sizeof(QueueItem));
	item->next = this->head;
	item->data = data;

	this->head = item;
}

void
queue_add(Queue *this, void *data)
{
	switch (this->type) {
	case FirstInLastOutQueue:
		lifo_add(this, data);
		return;
	default: /* FirstInFirstOutQueue */
		fifo_add(this, data);
		return;
	}
}

void
*fifo_remove(Queue *this)
{
	void *data = NULL;

	if (this->head != NULL) {
		QueueItem *item = this->head;
		data = item->data;
		this->head = item->next;
		free(item);
	}

	if (this->head == NULL) {
		this->tail = NULL;
	}

	return data;
}

void
*lifo_remove(Queue *this)
{
	void *data = NULL;

	if (this->head != NULL) {
		QueueItem *item = this->head;
		data = item->data;
		this->head = item->next;
		free(item);
	}

	return data;
}

void
*queue_remove(Queue *this)
{
	switch (this->type) {
	case FirstInLastOutQueue:
		return lifo_remove(this);
	default: /* FirstInFirstOutQueue */
		return fifo_remove(this);
	}
}