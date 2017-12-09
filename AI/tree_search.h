#include "common.h"
#include "fifo.h"
#include "graph.h"
#include "search_node.h"

#ifndef _TREE_SEARCH_H
#define _TREE_SEARCH_H

typedef struct tree_search tree_search;
struct tree_search {
	graph *graph;
	char *initial_state;
	char *goal_state;
	time_t start_time;
	time_t end_time;
	int nodes_used;
	queue *frontier;
	search_node *solution;
};

tree_search *tree_search_new(graph *graph, char *initial, char *goal);
void tree_search_free(tree_search *this);
int tree_search_search(tree_search *this);

#endif /* _TREE_SEARCH_H */
