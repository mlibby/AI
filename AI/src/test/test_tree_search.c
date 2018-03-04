#include "graph.h"
#include "test.h"
#include "test_tree_search.h"
#include "tree_search.h"

static graph_segment segments[] = {
	{ "NW", "NE", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "NE", "SE", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "SE", "SW", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "SW", "NW", 10, GRAPH_SEGMENT_UNDIRECTED },
	{ "NW", "SE", 14, GRAPH_SEGMENT_DIRECTED },
	{ "NE", "SW", 14, GRAPH_SEGMENT_DIRECTED },
	{ NULL, NULL, 0, 0 }
};

void
test_tree_search_new()
{
	graph *square = graph_create(segments);
	tree_search *search = tree_search_new(square);
	ASSERT(search->graph == square);
	tree_search_free(search);
}

void
test_tree_search_all()
{
	test_tree_search_new();
}