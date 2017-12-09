#include "tree_search.h"

tree_search *tree_search_new(graph *graph, char *initial, char *goal)
{
	tree_search *this = malloc(sizeof(this));
	this->graph = graph;
	this->initial_state = initial;
	this->goal_state = goal;
	this->start_time = 0;
	this->end_time = 0;
	this->nodes_used = 0;
	this->frontier = fifo_new();
	this->solution = NULL;
	return this;
}

void tree_search_free(tree_search *this)
{
	fifo_free(this->frontier);
	free(this);
}

//search_node **tree_search_expand_node(graph *graph, search_node *node, int *node_count) {
	//graph_vertex *vertex = graph_find_vertex(graph, node->state);
	//graph_edge *edge = vertex->edge;

//}

int tree_search_search(tree_search *this) {
	this->start_time = 1;

	search_node *first_node = search_node_new(this->initial_state, NULL, 0, NULL);
	fifo_add(this->frontier, first_node);
	this->nodes_used++;

	while (this->frontier->count > 0) {
		search_node *leaf_node = fifo_remove(this->frontier);
		if (strcmp(leaf_node->state, this->goal_state)) {
			//tree_search_build_solution(this, leaf_node);
		}
		else {
			//int new_node_count = 0;
			//search_node *new_nodes[] = tree_search_expand_node(this->graph, leaf_node, &new_node_count);
			//for (int i = 0; i < new_node_count; i++)
			//{
			//	fifo_add(this->frontier, new_nodes[i]);
			//}

			//this->nodes_used += new_node_count;
		}
	}

	this->end_time = 1;
	return 1;
}