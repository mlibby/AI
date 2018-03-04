#include "common.h"

#ifndef _SEARCH_NODE_H
#define _SEARCH_NODE_H

typedef struct search_node search_node;
struct search_node {
	char *state;
	char *action;
	int path_cost;
	search_node *parent;
	search_node *prev_node;
};

search_node *search_node_new(char *state, char *action, int path_cost, search_node *parent);
void search_node_free(search_node *this);

#endif /* _SEARCH_NODE_H */