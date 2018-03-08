#include <stdlib.h>
#include "ai_common.h"
#include "queue.h"

queue
*queue_new()
{
	queue *this = malloc(sizeof(queue));
	this->type = FirstInFirstOutQueue;
	this->head = NULL;
	this->tail = NULL;
	return this;
}

queue
*stack_new()
{
	queue *this = queue_new();
	this->type = FirstInLastOutQueue;
	return this;
}

void
queue_free(queue *this)
{
	while (queue_has_items(this)) {
		queue_remove(this);
	}
	free(this);
}

int
queue_has_items(queue *this)
{
	return this->head != NULL;
}

void
fifo_add(queue *this, void *data)
{
	queue_item *item = malloc(sizeof(queue_item)); 
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
lifo_add(queue *this, void *data)
{
	queue_item *item = malloc(sizeof(queue_item));
	item->next = this->head;
	item->data = data;

	this->head = item;
}

void
queue_add(queue *this, void *data)
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
*fifo_remove(queue *this)
{
	void *data = NULL;

	if (this->head != NULL) {
		queue_item *item = this->head;
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
*lifo_remove(queue *this)
{
	void *data = NULL;

	if (this->head != NULL) {
		queue_item *item = this->head;
		data = item->data;
		this->head = item->next;
		free(item);
	}

	return data;
}

void
*queue_remove(queue *this)
{
	switch (this->type) {
	case FirstInLastOutQueue:
		return lifo_remove(this);
	default: /* FirstInFirstOutQueue */
		return fifo_remove(this);
	}
}