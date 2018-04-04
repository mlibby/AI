#include "ai_common.h"
#include "search_node.h"

SearchNode *search_node_new(char *state, char *action, int path_cost, SearchNode *parent) {
	SearchNode *this = malloc(sizeof(SearchNode));
	this->state = state;
	this->action = action;
	this->path_cost = path_cost;
	this->parent = parent;
	return this;
}

void search_node_free(SearchNode *this) {
	free(this);
}
