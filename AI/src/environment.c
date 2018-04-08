#include <stdlib.h>
#include <string.h>
#include "environment.h"

Environment 
*environment_new(Graph *graph)
{
	Environment *this = malloc(sizeof(Environment));
	this->graph = graph;
	this->states = queue_new();
	return this;
}

void
environment_free(Environment *this)
{
	QueueItem *qi = this->states->head;
	while (qi != NULL) {
		free(qi->data);
		qi = qi->next;
	}
	queue_free(this->states);
	free(this);
}

void environment_add_state(Environment * this, const char * state)
{
	queue_add(this->states, strdup(state));
}

int environment_count_states(Environment * this)
{
	return queue_count_items(this->states);
}
