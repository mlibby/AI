#include "search_node.h"

search_node *search_node_new(char *state, char *action, int path_cost, search_node *parent) {
	search_node *this = malloc(sizeof(search_node));
	this->state = state;
	this->action = action;
	this->path_cost = path_cost;
	this->parent = parent;
	this->prev_node = NULL;

	return this;
}

void search_node_free(search_node *this) {
	free(this);
}
