#include <stdlib.h>
#include "ai_common.h"
#include "lifo.h"

lifo
*lifo_new()
{
	lifo *this = malloc(sizeof(lifo));
	this->head = NULL;
	return this;
}

void
lifo_free(lifo *this)
{
	while (lifo_has_items(this)) {
		lifo_remove(this);
	}
	free(this);
}

int
lifo_has_items(lifo *this)
{
	return this->head != NULL;
}

void
lifo_add(lifo *this, void *data)
{
	lifo_item *item = malloc(sizeof(lifo_item));
	item->next = this->head;
	item->data = data;

	this->head = item;
}


void
*lifo_remove(lifo *this)
{
	void *data = NULL;

	if (this->head != NULL) {
		lifo_item *item = this->head;
		data = item->data;
		this->head = item->next;
		free(item);
	}

	return data;
}
