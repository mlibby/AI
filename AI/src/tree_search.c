#include <stdlib.h>
#include "lifo.h"
#include "tree_search.h"

tree_search
*tree_search_new(graph *graph)
{
	tree_search *this = malloc(sizeof(tree_search));
	this->graph = graph;
	return this;
}

void 
tree_search_free(tree_search *this)
{
	free(this);
}

lifo 
*tree_search_search(tree_search *this, char *from, char *to)
{

	return NULL;
}
