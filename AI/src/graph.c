#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ai_common.h"
#include "graph.h"

graph
*graph_new()
{
	graph *this = malloc(sizeof(graph));
	this->head = NULL;
	this->tail = NULL;
	return this;
}

void
graph_vertex_free(graph_vertex *this)
{
	while (this->edge != NULL) {
		graph_edge *edge = this->edge;
		this->edge = edge->next;
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

graph_vertex
*graph_find_vertex(graph *this, char *name)
{
	graph_vertex *found = NULL;
	graph_vertex *vertex = this->head;
	while (found == NULL && vertex != NULL) {
		if (0 == strcmp(vertex->name, name)) {
			found = vertex;
		}
		vertex = vertex->next;
	}
	return found;
}

graph_vertex
*graph_vertex_new(char *name)
{
	graph_vertex *vertex = malloc(sizeof(graph_vertex));
	vertex->name = name;
	vertex->next = NULL;
	vertex->edge = NULL;
	return vertex;
}

graph_vertex
*graph_add_vertex(graph *this, char *name)
{
	graph_vertex *vertex = graph_find_vertex(this, name);

	if (vertex == NULL) {
		vertex = graph_vertex_new(name);

		if (this->head == NULL) {
			this->head = vertex;
			this->tail = vertex;
		}
		else {
			this->tail->next = vertex;
			this->tail = vertex;
		}
	}

	return vertex;
}

graph_edge
*graph_edge_new(graph_vertex *from, graph_vertex *to, int cost)
{
	graph_edge *edge = malloc(sizeof(graph_edge));
	edge->cost = cost;
	edge->to = to;
	edge->next = NULL;
	return edge;
}

int
graph_vertex_has_edge(graph_vertex *from, graph_vertex *to)
{
	graph_edge *edge = from->edge;
	while (edge != NULL) {
		if (edge->to == to) {
			return TRUE;
		}
		edge = edge->next;
	}
	return FALSE;
}

void
graph_create_edge(graph *this, graph_vertex *from, graph_vertex *to, int cost)
{
	graph_edge *edge = graph_edge_new(from, to, cost);

	if (from->edge == NULL) {
		from->edge = edge;
	}
	else {
		graph_edge *next = from->edge;
		while (next->next != NULL) {

			next = next->next;
		}
		next->next = edge;
	}
}

void
graph_add_edge(graph *this, char *from, char *to, int cost)
{
	graph_vertex *from_vertex = graph_find_vertex(this, from);
	graph_vertex *to_vertex = graph_find_vertex(this, to);

	if (from_vertex && to_vertex) {
		if (graph_vertex_has_edge(from_vertex, to_vertex)) {
			return;
		}
		graph_create_edge(this, from_vertex, to_vertex, cost);
	}
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

char
**graph_get_vertex_names(graph *this)
{
	int count = graph_vertex_count(this);
	char **names = malloc(sizeof(char*) * count);

	graph_vertex *vertex = this->head;
	for (int i = 0; i < count; i++) {
		names[i] = strdup(vertex->name);
		vertex = vertex->next;
	}

	return names;
}


int
graph_edge_count(graph *this)
{
	int count = 0;
	graph_vertex *vertex = this->head;
	while (vertex != NULL) {
		graph_edge *edge = vertex->edge;
		while (edge != NULL) {
			count++;
			edge = edge->next;
		}
		vertex = vertex->next;
	}
	return count;
}

void
graph_create_segment(graph *this, graph_segment segment)
{
	graph_vertex *from_vertex = graph_add_vertex(this, segment.from);
	graph_vertex *to_vertex = graph_add_vertex(this, segment.to);

	graph_create_edge(this, from_vertex, to_vertex, segment.cost);
	if (!segment.is_directed) {
		graph_create_edge(this, to_vertex, from_vertex, segment.cost);
	}
}

graph
*graph_create(graph_segment segments[])
{
	graph *this = graph_new();

	int x = 0;
	while (segments[x].to != NULL) {
		graph_create_segment(this, segments[x]);
		x++;
	}

	return this;
}
