#include <string.h>
#include "ai_common.h"
#include "search_node.h"

SearchNode *search_node_new(const char *state, const char *action, int path_cost, SearchNode *parent) {
	SearchNode *this = malloc(sizeof(SearchNode));
	this->state = strdup(state);
	this->action = strdup(action);
	this->path_cost = path_cost;
	this->parent = parent;
	return this;
}

void search_node_free(SearchNode *this) {
	free(this->state);
	free(this->action);
	free(this);
}
