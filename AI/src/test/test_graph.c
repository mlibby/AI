#include <stdlib.h>
#include "ai_common.h"
#include "graph.h"
#include "test.h"

void 
test_graph_new()
{
	Graph *graph = graph_new();
	ASSERT(graph != NULL);
	graph_free(graph);
}

void 
test_graph_add_vertices()
{
	Graph *graph = graph_new();
	ASSERT(0 == graph_vertex_count(graph));

	char *vertex_one = "Vertex One";
	graph_add_vertex(graph, vertex_one);

	ASSERT(0 == strcmp(graph->head->name, vertex_one));
	ASSERT(1 == graph_vertex_count(graph));

	char *vertex_two = "Vertex Two";
	graph_add_vertex(graph, vertex_two);
	ASSERT(2 == graph_vertex_count(graph));

	graph_free(graph);
}

void 
test_graph_add_duplicate_vertex()
{
	/* vertex names must be unique, adding duplicates is a noop */
	Graph *graph = graph_new();

	char *vertex_one = "Vertex One";
	graph_add_vertex(graph, vertex_one);

	ASSERT(0 == strcmp(graph->head->name, vertex_one));
	ASSERT(1 == graph_vertex_count(graph));

	graph_add_vertex(graph, vertex_one);
	ASSERT(1 == graph_vertex_count(graph));

	graph_free(graph);
}

void
test_graph_add_edge()
{
	Graph *graph = graph_new();

	char *vertex_one = "Vertex One";
	graph_add_vertex(graph, vertex_one);
	char *vertex_two = "Vertex Two";
	graph_add_vertex(graph, vertex_two);
	char *vertex_three = "Vertex Three";
	graph_add_vertex(graph, vertex_three);
	ASSERT(0 == graph_edge_count(graph));

	int cost = 1;
	graph_add_edge(graph, vertex_one, vertex_two, cost);
	ASSERT(1 == graph_edge_count(graph));

	graph_add_edge(graph, vertex_one, vertex_three, cost);
	ASSERT(2 == graph_edge_count(graph));

	graph_add_edge(graph, vertex_two, vertex_three, cost);
	ASSERT(3 == graph_edge_count(graph));

	/* cannot add duplicate edges (where to/from is the same) */
	graph_add_edge(graph, vertex_one, vertex_two, cost);
	ASSERT(3 == graph_edge_count(graph));

	graph_free(graph);
}

void
test_graph_find_missing_vertex()
{
	Graph *graph = graph_new();

	char *vertex_one = "Vertex One";
	graph_add_vertex(graph, vertex_one);

	GraphVertex *vertex = graph_find_vertex(graph, "Vertex Two");
	ASSERT(NULL == vertex);

	graph_free(graph);
}

static GraphSegment segments[] = {
	{ "NW", "NE", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "NE", "SE", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "SE", "SW", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "SW", "NW", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "NW", "SE", 14, GRAPH_SEGMENT_DIRECTED },
	{ "NE", "SW", 14, GRAPH_SEGMENT_DIRECTED },
	{ NULL, NULL, 0, 0}
};

void
test_graph_create()
{
	Graph *square = graph_create(segments);

	ASSERT(4 == graph_vertex_count(square));
	ASSERT(10 == graph_edge_count(square)); // six edges, but four are undirected (4 x 2) + 2 = 10

	GraphVertex *nw = graph_find_vertex(square, "NW");
	ASSERT(0 == strcmp("NW", nw->name));

	GraphEdge *edge = nw->edge;
	int edge_count = 0;

	int leads_to_ne = 0;
	int leads_to_se = 0;
	int leads_to_sw = 0;

	while (edge != NULL) {
		edge_count++;

		leads_to_ne += (0 == strcmp(edge->to->name, "NE")) ? 1 : 0;
		leads_to_se += (0 == strcmp(edge->to->name, "SE")) ? 1 : 0;
		leads_to_sw += (0 == strcmp(edge->to->name, "SW")) ? 1 : 0;

		edge = edge->next;
	}

	ASSERT(1 == leads_to_ne || 1 == leads_to_se || 1 == leads_to_sw);
	ASSERT(3 == edge_count);

	graph_free(square);
}

void 
test_graph_vertex_names()
{
	Graph *square = graph_create(segments);
	char **vertex_names = graph_get_vertex_names(square);
	int vertex_count = graph_vertex_count(square);

	sort_char_in_place(vertex_count, vertex_names);

	ASSERT(0 == strcmp("NE", vertex_names[0]));
	ASSERT(0 == strcmp("NW", vertex_names[1]));
	ASSERT(0 == strcmp("SE", vertex_names[2]));
	ASSERT(0 == strcmp("SW", vertex_names[3]));

	for (int i = 0; i < vertex_count; i++) {
		free(vertex_names[i]);
	}
	free(vertex_names);
	graph_free(square);
}

void
test_graph_create_grid_2x1()
{
	Graph *grid = graph_create_grid(2, 1);

	ASSERT(2 == graph_vertex_count(grid));
	ASSERT(2 == graph_edge_count(grid));
	ASSERT(0 == strcmp("0_0", grid->head->name));
	ASSERT(0 == strcmp("1_0", grid->head->edge->to->name));
	ASSERT(0 == strcmp("0_0", grid->head->edge->to->edge->to->name));
	
	graph_free(grid);
}

void
test_graph_can_store_data()
{
	Graph *grid = graph_create_grid(2, 1);
	graph_set_vertex_data(grid, "0_0", "DIRTY");
	graph_set_vertex_data(grid, "1_0", "CLEAN");

	ASSERT(0 == strcmp("DIRTY", graph_get_vertex_data(grid, "0_0")));
	ASSERT(0 == strcmp("CLEAN", graph_get_vertex_data(grid, "1_0")));

	graph_free(grid);
}

void
test_graph_create_grid_2x2()
{
	Graph *grid = graph_create_grid(2, 2);

	ASSERT(4 == graph_vertex_count(grid));
	ASSERT(8 == graph_edge_count(grid));

	graph_free(grid);
}

void
test_graph_create_grid_4x4()
{
	Graph *grid = graph_create_grid(4, 4);

	ASSERT(16 == graph_vertex_count(grid));
	ASSERT(48 == graph_edge_count(grid));

	graph_free(grid);
}

void
test_graph_all()
{
	test_graph_new();
	test_graph_add_vertices();
	test_graph_add_duplicate_vertex();
	test_graph_add_edge();
	test_graph_create();
	test_graph_create_grid_2x1();
	test_graph_create_grid_2x2();
	test_graph_create_grid_4x4();
	test_graph_find_missing_vertex();
	test_graph_vertex_names();
	test_graph_can_store_data();
}