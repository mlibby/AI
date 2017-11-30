#include "graph.h"
#include "romania.h"

int main(int argc, char* argv[]) {
	printf("Graph Demo\n");

	graph *romania = build_graph_romania();
	printf("Romania built\n");

	printf("Graph has %i vertices\n", romania->vertex_count);
	int i = 0;
	while(i < romania->vertex_count) {
		graph_vertex *vertex = romania->vertices[i];
		printf("Vertex %i: %s\n", i, vertex->name);
		i++;

		graph_edge *edge = vertex->edge;
		while (edge != NULL) {
			printf(" - %s (%i)\n", edge->to, edge->cost);
			edge = edge->next_edge;
		}
	}
}