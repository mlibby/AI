#include <stdlib.h>
#include <string.h>
#include "ai_common.h"
#include "breadth_search.h"
#include "queue.h"
#include "graph.h"
#include "search_node.h"

breadth_search
*breadth_search_new(graph *graph)
{
	breadth_search *this = malloc(sizeof(breadth_search));
	this->graph = graph;
	this->nodes = queue_new();
	this->frontier = queue_new();
	return this;
}

void 
breadth_search_free(breadth_search *this)
{
	search_node *node;
	while (queue_has_items(this->frontier)) {
		node = queue_remove(this->frontier);
	}
	while (queue_has_items(this->nodes)) {
		node = queue_remove(this->nodes);
		free(node);
	}
	queue_free(this->frontier);
	queue_free(this->nodes);
	free(this);
}

void
breadth_search_seed_frontier(breadth_search *this, char *name)
{
	search_node *node = search_node_new(name, NULL, 0, NULL);
	queue_add(this->nodes, node);
	queue_add(this->frontier, node);
}

void
breadth_search_expand_node(breadth_search *this, search_node *node)
{
	graph_vertex *vertex = graph_find_vertex(this->graph, node->state);
	graph_edge *edge = vertex->edge;
	while (NULL != edge) {
		search_node *edge_node = search_node_new(edge->to->name, edge->to->name, edge->cost, node);
		queue_add(this->nodes, edge_node);
		queue_add(this->frontier, edge_node);
		edge = edge->next;
	}
}

search_node 
*breadth_search_search(breadth_search *this, char *from, char *to)
{
	graph_vertex *vertex = graph_find_vertex(this->graph, from);
	if (NULL != vertex) {
		breadth_search_seed_frontier(this, vertex->name);

		while (queue_has_items(this->frontier)) {
			search_node *node = queue_remove(this->frontier);
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
