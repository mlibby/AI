 #include "common.h"

#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct graph graph;
typedef struct graph_vertex graph_vertex;
typedef struct graph_edge graph_edge;

struct graph {
	graph_vertex *head;
	graph_vertex *tail;
};

struct graph_vertex {
	char *name;
	graph_edge *edge; 
	graph_vertex *next;
};

struct graph_edge {
	int cost;
	char *to;
	graph_edge *next_edge;
};

graph *graph_new();
void graph_free(graph *this);

void graph_set_edges(graph *this, char *edges[][4]);
graph_vertex *graph_find_vertex(graph *this, char *name);
int graph_vertex_count(graph *this);

#endif /* _GRAPH_H */