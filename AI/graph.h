#include "common.h"

#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct _graph graph;
typedef struct _graph_vertex graph_vertex;
typedef struct _graph_edge graph_edge;

struct _graph {
	graph_vertex **vertices;
	int vertex_count;
};

struct _graph_vertex {
	char *name;
	graph_edge *edge;
};

struct _graph_edge {
	int cost;
	char *to;
	graph_edge *next_edge;
};

graph *graph_new(char *edges[][4]);
void graph_free(graph *this);
void graph_add_pair(graph *this, char *lname, char *rname, int cost);

#endif /* _GRAPH_H */