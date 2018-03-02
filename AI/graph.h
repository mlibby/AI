#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct graph graph;
typedef struct graph_vertex graph_vertex;
typedef struct graph_edge graph_edge;
typedef struct graph_segment graph_segment;

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
	graph_vertex *to;
	graph_edge *next;
};

struct graph_segment {
	char *from;
	char *to;
	int cost;
	int is_directed;
};

graph *graph_new();
graph *graph_create(graph_segment segments[]);
void graph_free(graph *this);

void graph_add_edge(graph *this, char *from, char *to, int cost);
graph_vertex *graph_add_vertex(graph *this, char *name);
graph_vertex *graph_find_vertex(graph *this, char *name);
char **graph_get_vertex_names(graph *this);
int graph_edge_count(graph *this);
int graph_vertex_count(graph *this);

#endif /* _GRAPH_H */