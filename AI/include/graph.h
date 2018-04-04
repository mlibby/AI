#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct graph Graph;
typedef struct graph_vertex GraphVertex;
typedef struct graph_edge GraphEdge;
typedef struct graph_segment GraphSegment;

struct graph {
	GraphVertex *head;
	GraphVertex *tail;
};

struct graph_vertex {
	char *name;
	GraphEdge *edge; 
	GraphVertex *next;
};

struct graph_edge {
	int cost;
	GraphVertex *to;
	GraphEdge *next;
};

#define GRAPH_SEGMENT_UNDIRECTED 0
#define GRAPH_SEGMENT_DIRECTED 1

struct graph_segment {
	char *from;
	char *to;
	int cost;
	int is_directed;
};

Graph *graph_new();
Graph *graph_create(GraphSegment segments[]);
Graph *graph_create_grid(int width, int height);
void graph_free(Graph *this);

void graph_add_edge(Graph *this, char *from, char *to, int cost);
GraphVertex *graph_add_vertex(Graph *this, char *name);
GraphVertex *graph_find_vertex(Graph *this, char *name);
char **graph_get_vertex_names(Graph *this);
int graph_edge_count(Graph *this);
int graph_vertex_count(Graph *this);

#endif /* _GRAPH_H */