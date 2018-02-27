#include "graph.h"
#include "romania.h"

char *edges[][4] = {
	{"NW", "10", "NE", "0"},
	{"NE", "10", "SE", "0"},
	{"SE", "10", "SW", "0"},
	{"SW", "10", "NW", "0"},
	{"NW", "14", "SE", "1"},
	{"NE", "14", "SW", "1"},
	{NULL, NULL, NULL, NULL}
};

int main(int argc, char* argv[]) {
	printf("Graph Demo\n");

	graph *square = graph_new();
	graph_set_edges(square, edges);

	printf("Square graph built\n");
	printf("Graph has %i vertices\n", graph_vertex_count(square));

	int i = 0;
	graph_vertex *vertex = square->head;
	while (vertex != NULL) {
		printf("Vertex %i: %s\n", i, vertex->name);
		i++;

		graph_edge *edge = vertex->edge;
		while (edge != NULL) {
			printf(" - %s (%i)\n", edge->to, edge->cost);
			edge = edge->next_edge;
		}
		vertex = vertex->next;
	}

	graph_free(square);
}