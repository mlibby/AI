#include "graph.h"

graph_vertex *graph_find_vertex(graph *this, char *name) {
	graph_vertex *vertex = NULL;
	int index = 0;
	while (index < this->vertex_count && (graph_vertex*)NULL == vertex) {
		if (!strcmp(name, this->vertices[index]->name)) {
			vertex = this->vertices[index];
		}
		else {
			index++;
		}
	}

	return vertex;
}

graph_vertex *graph_vertex_new(char *name) {
	graph_vertex *this = (graph_vertex *)malloc(sizeof(graph_vertex));
	this->name = name;
	this->edge = NULL;
	return this;
}

graph_vertex *graph_vertex_find_or_new(graph *this, char *name) {
	graph_vertex *vertex = graph_find_vertex(this, name);
	if (NULL == vertex) {
		vertex = graph_vertex_new(name);
		this->vertex_count++;
		if (NULL == this->vertices) {
			this->vertices = (graph_vertex **)malloc(sizeof(graph_vertex*));
		}
		else {
			this->vertices = (graph_vertex **)realloc(this->vertices, sizeof(graph_vertex*) * this->vertex_count);
		}
		this->vertices[this->vertex_count - 1] = vertex;
	}
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

graph *graph_new(char *edges[][4]) {
	graph *this = (graph *)malloc(sizeof(graph));
	this->vertex_count = 0;
	this->vertices = NULL;

	int edge_count = 0;
	char **edge;
	edge = (char **)edges[edge_count];
	while (edge[0] != NULL) {
		graph_vertex *from = graph_vertex_find_or_new(this, edge[0]);
		graph_vertex *to = graph_vertex_find_or_new(this, edge[2]);

		int cost = 0;
		int parsed = sscanf(edge[1], "%d", &cost);
		if (parsed) {
			graph_vertex_add_edge(from, to->name, cost);
			if (strncmp("0", edge[3], 1)) {
				graph_vertex_add_edge(to, from->name, cost);
			}
		}

		edge_count++;
		edge = (char **)edges[edge_count];
	}

	return this;
}

void graph_free(graph *this) {
	free(this->vertices);
	free(this);
}
