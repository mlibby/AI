#include "graph.h"

graph *graph_new(int vertex_count) {
	graph *this = (graph *)malloc(sizeof(graph));

	this->vertex_count = vertex_count;

	graph_vertex **vertices = (graph_vertex **)malloc(sizeof(graph_vertex*) * vertex_count);
	this->vertices = vertices;
	int i = 0;
	while (i < vertex_count) {
		this->vertices[i] = NULL;
		i++;
	}

	return this;
}

void graph_free(graph *this) {
	free(this->vertices);
	free(this);
}

graph_vertex *graph_vertex_new(char *name) {
	graph_vertex *vertex = (graph_vertex *)malloc(sizeof(graph_vertex));
	vertex->name = name;
	vertex->edge = NULL;
	return vertex;
}

graph_edge *graph_edge_new(char *name, int cost) {
	graph_edge *edge = (graph_edge *)malloc(sizeof(graph_edge));
	edge->to = name;
	edge->cost = cost;
	edge->next_edge = NULL;

	return edge;
}

void graph_vertex_add_edge(graph_vertex *vertex, char *name, int cost) {
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

void graph_add_pair(graph *this, char *lname, char *rname, int cost) {
	int matched = FALSE;
	int index = 0;
	while (index < this->vertex_count && !matched) {
		matched = (NULL == this->vertices[index]);
		if (!matched) {
			if (!strcmp(lname, this->vertices[index]->name)) {
				matched = TRUE;
			}
			else {
				index++;
			}
		}
	}

	if (index < this->vertex_count)
	{
		if (NULL == this->vertices[index]) {
			this->vertices[index] = graph_vertex_new(lname);
		}
	}
	else {
		printf("WARNING: attempted to add pair with vertex past max vertex count for graph\n");
	}

	graph_vertex_add_edge(this->vertices[index], rname, cost);
}
