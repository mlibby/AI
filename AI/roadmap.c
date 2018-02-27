#include "roadmap.h"
#include "sort.h"

void roadmap_build_cities(roadmap *this) {
	int vertex_count = graph_vertex_count(this->graph);
	char **city_names = malloc(sizeof(char*) * vertex_count);

	graph_vertex *vertex = this->graph->head;
	for (int i = 0; i < vertex_count; i++) {
		city_names[i] = strdup(vertex->name);
		vertex = vertex->next;
	}

	sort_char_in_place(vertex_count, city_names);
	this->city_names = city_names;
	this->city_count = vertex_count;
}

roadmap *roadmap_new(char *routes[][4]) {
	roadmap *this = malloc(sizeof(roadmap));
	this->city_count = 0;
	this->city_names = NULL;
	this->graph = graph_new();
	graph_set_edges(this->graph, routes);
	roadmap_build_cities(this);
	return this;
}

void roadmap_city_names_free(roadmap *this) {
	for (int i = 0; i < this->city_count; i++) {
		free(this->city_names[i]);
	}

	free(this->city_names);
}

void roadmap_free(roadmap *this) {
	roadmap_city_names_free(this);
	graph_free(this->graph);
	free(this);
}

