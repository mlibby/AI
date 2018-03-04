#ifndef _TREE_SEARCH_H
#define _TREE_SEARCH_H

#include "graph.h"

typedef struct tree_search tree_search;
struct tree_search {
	graph *graph;
//	char *initial_state;
//	char *goal_state;
//	clock_t start_time;
//	clock_t end_time;
//	int nodes_used;
//	search_node *tail_node;
//	fifo *frontier;
//	search_node *solution;
};

tree_search *tree_search_new(graph *graph);
void tree_search_free(tree_search *this);

#endif /* _TREE_SEARCH_H */
