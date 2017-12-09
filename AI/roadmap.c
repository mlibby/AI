#include "common.h"
#include "roadmap.h"
#include "sort.h"

roadmap *roadmap_new(char *routes[][4]) {
	roadmap *this = malloc(sizeof(this));
	this->is_updated = FALSE;
	this->city_count = 0;
	this->city_names = NULL;
	this->graph = graph_new(routes);
	return this;
}

void roadmap_city_names_free(roadmap *this) {
	for (int i = 0; i < this->city_count; i++) {
		free(this->city_names[i]);
	}

	free(this->city_names);
}

void roadmap_update(roadmap *this) {
	if (this->city_names != NULL) {
		roadmap_city_names_free(this);
	}

	char **city_names = malloc(sizeof(char*) * this->graph->vertex_count);

	for (int i = 0; i < this->graph->vertex_count; i++) {
		city_names[i] = strdup(this->graph->vertices[i]->name);
	}

	sort_char_in_place(this->graph->vertex_count, city_names);
	
	this->city_names = city_names;
	this->city_count = this->graph->vertex_count;
}

int roadmap_city_count(roadmap *this)
{
	if (!this->is_updated) {
		roadmap_update(this);
	}
	return this->city_count;
}


void roadmap_free(roadmap *this) {
	graph_free(this->graph);
	free(this);
}

