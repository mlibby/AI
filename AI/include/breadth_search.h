#ifndef _BREADTH_SEARCH_H
#define _BREADTH_SEARCH_H

#include "queue.h"
#include "graph.h"
#include "search_node.h"

typedef struct breadth_search BreadthSearch;
struct breadth_search {
	Graph *graph;
	Queue *nodes;
	Queue *frontier;
};

BreadthSearch *breadth_search_new(Graph *graph);
void breadth_search_free(BreadthSearch *this);

SearchNode *breadth_search_search(BreadthSearch *this, char *from, char *to);

#endif /* _BREADTH_SEARCH_H */
