#include <stdlib.h>
#include <string.h>
#include "ai_common.h"
#include "breadth_search.h"
#include "fifo.h"
#include "graph.h"
#include "search_node.h"

breadth_search
*breadth_search_new(graph *graph)
{
	breadth_search *this = malloc(sizeof(breadth_search));
	this->graph = graph;
	this->nodes = fifo_new();
	this->frontier = fifo_new();
	return this;
}

void 
breadth_search_free(breadth_search *this)
{
	search_node *node;
	while (fifo_has_items(this->frontier)) {
		node = fifo_remove(this->frontier);
	}
	while (fifo_has_items(this->nodes)) {
		node = fifo_remove(this->nodes);
		free(node);
	}
	fifo_free(this->frontier);
	fifo_free(this->nodes);
	free(this);
}

void
breadth_search_seed_frontier(breadth_search *this, char *name)
{
	search_node *node = search_node_new(name, NULL, 0, NULL);
	fifo_add(this->nodes, node);
	fifo_add(this->frontier, node);
}

void
breadth_search_expand_node(breadth_search *this, search_node *node)
{
	graph_vertex *vertex = graph_find_vertex(this->graph, node->state);
	graph_edge *edge = vertex->edge;
	while (NULL != edge) {
		search_node *edge_node = search_node_new(edge->to->name, edge->to->name, edge->cost, node);
		fifo_add(this->nodes, edge_node);
		fifo_add(this->frontier, edge_node);
		edge = edge->next;
	}
}

search_node 
*breadth_search_search(breadth_search *this, char *from, char *to)
{
	graph_vertex *vertex = graph_find_vertex(this->graph, from);
	if (NULL != vertex) {
		breadth_search_seed_frontier(this, vertex->name);

		while (fifo_has_items(this->frontier)) {
			search_node *node = fifo_remove(this->frontier);
			if (0 == strcmp(to, node->state)) {
				return node;
			}
			else {
				breadth_search_expand_node(this, node);
			}
		}
	}
	return NULL;
}
