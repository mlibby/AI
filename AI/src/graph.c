#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ai_common.h"
#include "graph.h"

Graph
*graph_new()
{
	Graph *this = malloc(sizeof(Graph));
	this->head = NULL;
	this->tail = NULL;
	return this;
}

void
graph_vertex_free(GraphVertex *this)
{
	while (this->edge != NULL) {
		GraphEdge *edge = this->edge;
		this->edge = edge->next;
		free(edge);
	}
	free(this->name);
	free(this);
}

void
graph_free(Graph *this)
{
	while (this->head != NULL) {
		GraphVertex *vertex = this->head;
		this->head = vertex->next;
		graph_vertex_free(vertex);
	}
	free(this);
}

GraphVertex
*graph_find_vertex(Graph *this, char *name)
{
	GraphVertex *found = NULL;
	GraphVertex *vertex = this->head;
	while (found == NULL && vertex != NULL) {
		if (0 == strcmp(vertex->name, name)) {
			found = vertex;
		}
		vertex = vertex->next;
	}
	return found;
}

GraphVertex
*graph_vertex_new(char *name)
{
	GraphVertex *vertex = malloc(sizeof(GraphVertex));
	vertex->name = strdup(name);
	vertex->next = NULL;
	vertex->edge = NULL;
	return vertex;
}

GraphVertex
*graph_add_vertex(Graph *this, char *name)
{
	GraphVertex *vertex = graph_find_vertex(this, name);

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

GraphEdge
*graph_edge_new(GraphVertex *from, GraphVertex *to, int cost)
{
	GraphEdge *edge = malloc(sizeof(GraphEdge));
	edge->cost = cost;
	edge->to = to;
	edge->next = NULL;
	return edge;
}

int
graph_vertex_has_edge(GraphVertex *from, GraphVertex *to)
{
	GraphEdge *edge = from->edge;
	while (edge != NULL) {
		if (edge->to == to) {
			return TRUE;
		}
		edge = edge->next;
	}
	return FALSE;
}

void
graph_create_edge(Graph *this, GraphVertex *from, GraphVertex *to, int cost)
{
	GraphEdge *edge = graph_edge_new(from, to, cost);

	if (from->edge == NULL) {
		from->edge = edge;
	}
	else {
		GraphEdge *next = from->edge;
		while (next->next != NULL) {

			next = next->next;
		}
		next->next = edge;
	}
}

void
graph_add_edge(Graph *this, char *from, char *to, int cost)
{
	GraphVertex *from_vertex = graph_find_vertex(this, from);
	GraphVertex *to_vertex = graph_find_vertex(this, to);

	if (from_vertex && to_vertex) {
		if (graph_vertex_has_edge(from_vertex, to_vertex)) {
			return;
		}
		graph_create_edge(this, from_vertex, to_vertex, cost);
	}
}

int
graph_vertex_count(Graph *this)
{
	int count = 0;
	GraphVertex *vertex = this->head;
	while (vertex != NULL) {
		count++;
		vertex = vertex->next;
	}
	return count;
}

char
**graph_get_vertex_names(Graph *this)
{
	int count = graph_vertex_count(this);
	char **names = malloc(sizeof(char*) * count);

	GraphVertex *vertex = this->head;
	for (int i = 0; i < count; i++) {
		names[i] = strdup(vertex->name);
		vertex = vertex->next;
	}

	return names;
}


int
graph_edge_count(Graph *this)
{
	int count = 0;
	GraphVertex *vertex = this->head;
	while (vertex != NULL) {
		GraphEdge *edge = vertex->edge;
		while (edge != NULL) {
			count++;
			edge = edge->next;
		}
		vertex = vertex->next;
	}
	return count;
}

void
graph_create_segment(Graph *this, GraphSegment segment)
{
	GraphVertex *from_vertex = graph_add_vertex(this, segment.from);
	GraphVertex *to_vertex = graph_add_vertex(this, segment.to);

	graph_create_edge(this, from_vertex, to_vertex, segment.cost);
	if (!segment.is_directed) {
		graph_create_edge(this, to_vertex, from_vertex, segment.cost);
	}
}

Graph
*graph_create(GraphSegment segments[])
{
	Graph *this = graph_new();

	int x = 0;
	while (segments[x].to != NULL) {
		graph_create_segment(this, segments[x]);
		x++;
	}

	return this;
}

Graph
*graph_create_grid(int width, int height)
{
	Graph *this = graph_new();

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			char from[64];
			char to[64];

			if (x + 1 < width) {
				sprintf(from, "%i_%i", x, y);
				sprintf(to, "%i_%i", x + 1, y);
				GraphSegment segment = { from, to, 1, GRAPH_SEGMENT_UNDIRECTED };
				graph_create_segment(this, segment);
			}

			if (y + 1 < height) {
				sprintf(from, "%i_%i", x, y);
				sprintf(to, "%i_%i", x, y + 1);
				GraphSegment segment = { from, to, 1, GRAPH_SEGMENT_UNDIRECTED };
				graph_create_segment(this, segment);
			}
		}
	}

	return this;
}

