#include <stdlib.h>
#include "environment.h"

Environment 
*environment_new(Graph *graph)
{
	Environment *this = malloc(sizeof(Environment));
	this->graph = graph;
	return this;
}

void
environment_free(Environment *this)
{
	free(this);
}