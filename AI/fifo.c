#include <stdlib.h>
#include <stdio.h>
#include "fifo.h"

fifo *fifo_new()
{
	fifo *this = malloc(sizeof(fifo));
	this->head = NULL;
	this->tail = NULL;
	return this;
}

fifo_item *fifo_item_new(fifo *this, void *data)
{
	fifo_item *item = malloc(sizeof(fifo_item));
	item->next = NULL;
	item->data = data;
	return item;
}

void fifo_free(fifo *this)
{
	printf("fifo free\n");
	while (fifo_has_items(this)) {
		fifo_remove(this);
	}
	free(this);
}

int fifo_has_items(fifo *this)
{
	return !(this->head == NULL);
}

void fifo_add(fifo *this, void *data)
{
	fifo_item *item = fifo_item_new(this, data);

	if (this->head == NULL) {
		this->head = item;
	}

	if (this->tail != NULL) {
		(this->tail)->next = item;
	}

	this->tail = item;
}

void *fifo_remove(fifo *this)
{
	printf("fifo remove\n");
	void *data = NULL;

	if (this->head != NULL) {
		fifo_item *item = this->head;
		printf("pulled item from head %p\n", item);
		data = item->data;
		this->head = item->next;
		free(item);
	}

	return data;
}
