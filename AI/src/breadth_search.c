#include <stdlib.h>
#include <string.h>
#include "ai_common.h"
#include "breadth_search.h"
#include "queue.h"
#include "graph.h"
#include "search_node.h"

BreadthSearch
*breadth_search_new(Graph *graph)
{
	BreadthSearch *this = malloc(sizeof(BreadthSearch));
	this->graph = graph;
	this->nodes = queue_new();
	this->frontier = queue_new();
	return this;
}

void 
breadth_search_free(BreadthSearch *this)
{
	SearchNode *node;
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
breadth_search_seed_frontier(BreadthSearch *this, char *name)
{
	SearchNode *node = search_node_new(name, NULL, 0, NULL);
	queue_add(this->nodes, node);
	queue_add(this->frontier, node);
}

void
breadth_search_expand_node(BreadthSearch *this, SearchNode *node)
{
	GraphVertex *vertex = graph_find_vertex(this->graph, node->state);
	GraphEdge *edge = vertex->edge;
	while (NULL != edge) {
		SearchNode *edge_node = search_node_new(edge->to->name, edge->to->name, edge->cost, node);
		queue_add(this->nodes, edge_node);
		queue_add(this->frontier, edge_node);
		edge = edge->next;
	}
}

SearchNode 
*breadth_search_search(BreadthSearch *this, char *from, char *to)
{
	GraphVertex *vertex = graph_find_vertex(this->graph, from);
	if (NULL != vertex) {
		breadth_search_seed_frontier(this, vertex->name);

		while (queue_has_items(this->frontier)) {
			SearchNode *node = queue_remove(this->frontier);
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
