#include <stdlib.h>
#include "ai_common.h"
#include "fifo.h"

fifo
*fifo_new()
{
	fifo *this = malloc(sizeof(fifo));
	this->head = NULL;
	this->tail = NULL;
	return this;
}

void
fifo_free(fifo *this)
{
	while (fifo_has_items(this)) {
		fifo_remove(this);
	}
	free(this);
}

int
fifo_has_items(fifo *this)
{
	return this->head != NULL;
}

void
fifo_add(fifo *this, void *data)
{
	fifo_item *item = malloc(sizeof(fifo_item));
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
*fifo_remove(fifo *this)
{
	void *data = NULL;

	if (this->head != NULL) {
		fifo_item *item = this->head;
		data = item->data;
		this->head = item->next;
		free(item);
	}

	if (this->head == NULL) {
		this->tail = NULL;
	}


	return data;
}
