#include "fifo.h"
#include "graph.h"
#include "test.h"
#include "test_tree_search.h"
#include "tree_search.h"

void
test_tree_search_new()
{
	graph_segment segments[] = {
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	tree_search *search = tree_search_new(square);
	ASSERT(search->graph == square);
	tree_search_free(search);
	graph_free(square);
}

void
test_tree_search_empty_frontier_fails()
{
	graph_segment segments[] = {
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	tree_search *search = tree_search_new(square);
	fifo *solution = tree_search_search(search, "From", "To");
	ASSERT(NULL == solution);
	tree_search_free(search);
	graph_free(square);
}

void
test_tree_search_from_to_same()
{
	graph_segment segments[] = {
		{"FROM", "TO", 1, GRAPH_SEGMENT_DIRECTED},
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	tree_search *search = tree_search_new(square);
	fifo *solution = tree_search_search(search, "From", "From");

	ASSERT(NULL != solution);
	tree_search_free(search);
	graph_free(square);
}

void
test_tree_search_all()
{
	test_tree_search_new();
	test_tree_search_empty_frontier_fails();
	test_tree_search_from_to_same();
}