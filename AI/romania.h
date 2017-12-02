#ifndef _ROMANIA_H
#define _ROMANIA_H

#include "common.h"
#include "graph.h"

graph *romania_build_graph();
char **romania_get_city_names(graph *romania);
void romania_free_city_names(graph *romania, char **cities);
int romania_get_city_count(graph *romania);
void romania_free(graph *romania);

#endif /* _ROMANIA_H */