#ifndef _ROADMAP_H
#define _ROADMAP_H

#include "common.h"
#include "graph.h"

typedef struct roadmap roadmap;
struct roadmap {
	graph *graph;
	char **city_names;
};

roadmap *roadmap_new(char *routes[][4]);
int roadmap_city_count(roadmap *this);
void roadmap_free(roadmap *this);

#endif /* _ROADMAP_H */