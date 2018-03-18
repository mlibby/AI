#include <stdlib.h>
#include "environment.h"

environment 
*environment_new(graph *graph)
{
	environment *this = malloc(sizeof(environment));
	this->graph = graph;
	return this;
}

void
environment_free(environment *this)
{
	free(this);
}