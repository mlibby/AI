#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
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
graph_create_vertices_and_edge(graph *this, char *from, char *to, int cost, int is_directed)
{
	graph_vertex *from_vertex = graph_add_vertex(this, from);
	graph_vertex *to_vertex = graph_add_vertex(this, to);

	graph_create_edge(this, from_vertex, to_vertex, cost);
	if (!is_directed) {
		graph_create_edge(this, to_vertex, from_vertex, cost);
	}
}

graph
*graph_create(char *edges[][4])
{
	graph *this = graph_new();

	int x = 0;
	while (edges[x][0] != NULL) {
		int cost = 0;
		if (sscanf(edges[x][1], "%d", &cost)) {
			int is_directed = edges[x][3][0] == '1';
			graph_create_vertices_and_edge(this, edges[x][0], edges[x][2], cost, is_directed);
		}
		x++;
	}
	
	return this;
}

