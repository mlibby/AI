#include "tree_search.h"

tree_search 
*tree_search_new(graph *graph)
{
	tree_search *this = malloc(sizeof(tree_search));
	this->graph = graph;
	this->nodes_used = 0;
	this->frontier = fifo_new();
	this->solution = NULL;
	this->tail_node = NULL;
	return this;
}

void 
tree_search_free(tree_search *this)
{
	while (this->tail_node != NULL) {
		search_node *prev_node = this->tail_node->prev_node;
		search_node_free(this->tail_node);
		this->tail_node = prev_node;
	}
	fifo_free(this->frontier);
	free(this);
}

void
tree_search_build_solution(tree_search *this, search_node *node)
{

}

search_node
**tree_search_expand_node(tree_search *this, search_node *node, int *node_count) 
{
	graph_vertex *vertex = graph_find_vertex(this->graph, node->state);
	graph_edge *edge = vertex->edge;
	int edge_count = 0;
	while (edge != NULL) {
		edge = edge->next_edge;
		edge_count++;
	}

	search_node **new_nodes = malloc(sizeof(search_node) * edge_count);
	edge = vertex->edge;
	int new_node_count = 0;
	while (edge != NULL) {
		search_node *new_node = search_node_new(edge->to, edge->to, edge->cost, node);
		new_nodes[new_node_count] = new_node;
		if (this->tail_node != NULL) {
			new_node->prev_node = this->tail_node;
		}
		this->tail_node = new_node;
	}

	return NULL;
}

int
tree_search_expand_node_to_frontier(tree_search *this, search_node *node)
{
	int new_node_count = 0;
	search_node **new_nodes = tree_search_expand_node(this, node, &new_node_count);
	for (int i = 0; i < new_node_count; i++)
	{
		fifo_add(this->frontier, new_nodes[i]);
	}

	return new_node_count;
}

void
tree_search_init_frontier(tree_search *this)
{
	search_node *first_node = search_node_new(this->initial_state, NULL, 0, NULL);
	fifo_add(this->frontier, first_node);
	this->nodes_used++;
}

void
tree_search_process_frontier_node(tree_search *this)
{
	search_node *node = fifo_remove(this->frontier);
	if (strcmp(node->state, this->goal_state)) {
		tree_search_build_solution(this, node);
	} else {
		this->nodes_used += tree_search_expand_node_to_frontier(this, node);
	}
}

int 
tree_search_search(tree_search *this, char *initial_state, char *goal_state) {
	this->initial_state = initial_state;
	this->goal_state = goal_state;
	this->start_time = clock();

	tree_search_init_frontier(this);
	while (fifo_has_items(this->frontier)) {
		tree_search_process_frontier_node(this);
	}

	this->end_time = clock();
	return TRUE;
}