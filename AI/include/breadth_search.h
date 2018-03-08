#ifndef _BREADTH_SEARCH_H
#define _BREADTH_SEARCH_H

#include "queue.h"
#include "graph.h"
#include "search_node.h"

typedef struct breadth_search breadth_search;
struct breadth_search {
	graph *graph;
	queue *nodes;
	queue *frontier;
};

breadth_search *breadth_search_new(graph *graph);
void breadth_search_free(breadth_search *this);

search_node *breadth_search_search(breadth_search *this, char *from, char *to);

#endif /* _BREADTH_SEARCH_H */
