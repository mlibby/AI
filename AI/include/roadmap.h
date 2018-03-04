#include "common.h"
#include "graph.h"

#ifndef _ROADMAP_H
#define _ROADMAP_H

typedef struct roadmap roadmap;
struct roadmap {
	int city_count;
	char **city_names;
	graph *graph;
};

roadmap *roadmap_new(char *routes[][4]);
void roadmap_free(roadmap *this);

#endif /* _ROADMAP_H */