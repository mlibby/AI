#ifndef _SEARCH_NODE_H
#define _SEARCH_NODE_H

typedef struct search_node SearchNode;
struct search_node {
	char *state;
	char *action;
	int path_cost;
	SearchNode *parent;
};

SearchNode *search_node_new(char *state, char *action, int path_cost, SearchNode *parent);
void search_node_free(SearchNode *this);

#endif /* _SEARCH_NODE_H */