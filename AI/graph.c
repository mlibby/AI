#include "graph.h"

graph_vertex
*graph_find_vertex(graph *this, char *name)
{
	graph_vertex *vertex = this->head;

	while (vertex != NULL) {
		if (!strcmp(name, vertex->name)) {
			return vertex;
		}
		else {
			vertex = vertex->next;
		}
	}

	return NULL;
}

graph_vertex
*graph_graph_vertex_new(graph *this, char *name)
{
	graph_vertex *vertex = malloc(sizeof(graph_vertex));
	vertex->name = name;
	vertex->edge = NULL;
	vertex->next = NULL;

	if (this->head == NULL) {
		this->head = vertex;
		this->tail = vertex;
	}
	else {
		this->tail->next = vertex;
		this->tail = vertex;
	}

	return vertex;
}

graph_vertex
*graph_find_or_new_vertex(graph *this, char *name)
{
	graph_vertex *vertex = graph_find_vertex(this, name);
	if (NULL == vertex) {
		vertex = graph_graph_vertex_new(this, name);
	}
	return vertex;
}

graph_edge
*graph_edge_new(char *name, int cost)
{
	graph_edge *edge = malloc(sizeof(graph_edge));
	edge->to = name;
	edge->cost = cost;
	edge->next_edge = NULL;

	return edge;
}

void
graph_vertex_add_edge(graph_vertex *vertex, char *name, int cost)
{
	graph_edge *new_edge = graph_edge_new(name, cost);

	graph_edge *edge = vertex->edge;
	if (NULL == edge) {
		vertex->edge = new_edge;
	}
	else {
		while (edge->next_edge != NULL) {
			edge = edge->next_edge;
		}
		edge->next_edge = new_edge;
	}
}

graph
*graph_new()
{
	graph *this = malloc(sizeof(graph));
	this->head = NULL;
	this->tail = NULL;
	return this;
}

void
graph_add_edge(graph *this, char *from, char *to, int cost, int is_directed)
{
	graph_vertex *from_v = graph_find_or_new_vertex(this, from);
	graph_vertex *to_v = graph_find_or_new_vertex(this, to);

	graph_vertex_add_edge(from_v, to_v->name, cost);
	if (!is_directed) {
		graph_vertex_add_edge(to_v, from_v->name, cost);
	}
}

void
graph_set_edges(graph *this, char *edges[][4])
{
	int edge_index = 0;
	while (edges[edge_index][0] != NULL) {
		int cost = 0;
		if (sscanf(edges[edge_index][1], "%d", &cost)) {
			int is_directed = strncmp("0", edges[edge_index][3], 1);
			graph_add_edge(this, edges[edge_index][0], edges[edge_index][2], cost, is_directed);
		}
		edge_index++;
	}
}

void 
graph_vertex_free(graph_vertex *this)
{
	while (this->edge != NULL) {
		graph_edge *edge = this->edge;
		this->edge = edge->next_edge;
		free(edge);
	}
	free(this);
}

void
graph_free(graph *this)
{
	while (this->head != NULL) {
		graph_vertex *vertex = this->head;
		this->head = vertex->next;
		graph_vertex_free(vertex);
	}

	free(this);
}

int
graph_vertex_count(graph *this)
{
	int count = 0;
	graph_vertex *vertex = this->head;
	while (vertex != NULL) {
		count++;
		vertex = vertex->next;
	}
	return count;
}
