#include "common.h"
#include "test.h"
#include "graph.h"

void test_graph_new()
{
	graph *graph = graph_new();
	ASSERT(graph != NULL);
	graph_free(graph);
}

void test_graph_add_vertices()
{
	graph *graph = graph_new();
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

/* vertex names must be unique */
void test_graph_add_duplicate_vertex()
{
	graph *graph = graph_new();

	char *vertex_one = "Vertex One";
	graph_add_vertex(graph, vertex_one);

	ASSERT(0 == strcmp(graph->head->name, vertex_one));
	ASSERT(1 == graph_vertex_count(graph));

	graph_add_vertex(graph, vertex_one);
	ASSERT(1 == graph_vertex_count(graph));

	graph_free(graph);
}

void test_graph_add_edge()
{
	graph *graph = graph_new();

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

	graph_add_edge(graph, vertex_one, vertex_two, cost);
	ASSERT(3 == graph_edge_count(graph));

	graph_free(graph);
}

void test_graph_create()
{
	/* 
	* format is: 
	* 1. From name
	* 2. Cost
	* 3. To name
	* 4. 0 == undirected edge, 1 == directed edge
	*/
	char *edges[][4] = {
		{ "NW", "10", "NE", "0" },
		{ "NE", "10", "SE", "0" },
		{ "SE", "10", "SW", "0" },
		{ "SW", "10", "NW", "0" },
		{ "NW", "14", "SE", "1" },
		{ "NE", "14", "SW", "1" },
		{ NULL, NULL, NULL, NULL }
	};

	graph *square = graph_create(edges);

	ASSERT(4 == graph_vertex_count(square));
	ASSERT(10 == graph_edge_count(square)); // six edges, but four are undirected (4 x 2) + 2 = 10

	graph_vertex *nw = graph_find_vertex(square, "NW");
	ASSERT(0 == strcmp("NW", nw->name));

	graph_edge *edge = nw->edge;
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

void test_graph_all()
{
	test_graph_new();
	test_graph_add_vertices();
	test_graph_add_duplicate_vertex();
	test_graph_add_edge();
	test_graph_create();
}