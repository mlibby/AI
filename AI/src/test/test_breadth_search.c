#include "queue.h"
#include "graph.h"
#include "test.h"
#include "test_breadth_search.h"
#include "breadth_search.h"

void
test_breadth_search_new()
{
	graph_segment segments[] = {
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	breadth_search *search = breadth_search_new(square);
	ASSERT(search->graph == square);
	breadth_search_free(search);
	graph_free(square);
}

void
test_breadth_search_empty_frontier_fails()
{
	graph_segment segments[] = {
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	breadth_search *search = breadth_search_new(square);
	search_node *solution = breadth_search_search(search, "From", "To");
	ASSERT(NULL == solution);
	breadth_search_free(search);
	graph_free(square);
}

void
test_breadth_search_from_to_same()
{
	graph_segment segments[] = {
		{"FROM", "TO", 1, GRAPH_SEGMENT_DIRECTED},
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	breadth_search *search = breadth_search_new(square);
	search_node *solution = breadth_search_search(search, "FROM", "FROM");

	ASSERT(NULL != solution);
	ASSERT(NULL == solution->parent);
	ASSERT(0 == solution->path_cost);
	ASSERT(0 == strcmp("FROM", solution->state));
	ASSERT(NULL == solution->action);

	breadth_search_free(search);
	graph_free(square);
}

void
test_breadth_search_single_segment()
{
	graph_segment segments[] = {
		{ "FROM", "TO", 1, GRAPH_SEGMENT_DIRECTED },
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	breadth_search *search = breadth_search_new(square);
	search_node *solution = breadth_search_search(search, "FROM", "TO");

	ASSERT(NULL != solution);

	ASSERT(0 == strcmp("TO", solution->state));
	ASSERT(0 == strcmp("TO", solution->action));
	ASSERT(1 == solution->path_cost);

	search_node *parent = solution->parent;
	ASSERT(NULL == parent->parent);
	ASSERT(0 == strcmp("FROM", parent->state));
	ASSERT(NULL == parent->action);
	ASSERT(0 == parent->path_cost);

	breadth_search_free(search);
	graph_free(square);
}

void
test_breadth_search_one_shortest_path()
{
	graph_segment segments[] = {
		{ "FROM", "MID1", 1, GRAPH_SEGMENT_DIRECTED },
		{ "FROM", "MID2", 1, GRAPH_SEGMENT_DIRECTED },
		{ "MID2", "TO", 1, GRAPH_SEGMENT_DIRECTED },
		{ "MID1", "MID3", 1, GRAPH_SEGMENT_DIRECTED },
		{ "MID3", "TO", 1, GRAPH_SEGMENT_DIRECTED },
		{ NULL, NULL, 0, 0 }
	};

	graph *square = graph_create(segments);
	breadth_search *search = breadth_search_new(square);
	search_node *solution = breadth_search_search(search, "FROM", "TO");

	ASSERT(NULL != solution);
	ASSERT(0 == strcmp("TO", solution->state));

	search_node *mid = solution->parent;
	ASSERT(0 == strcmp("MID2", mid->state));

	search_node *from = mid->parent;
	ASSERT(0 == strcmp("FROM", from->state));
	ASSERT(NULL == from->parent);

	breadth_search_free(search);
	graph_free(square);
}

void
test_breadth_search_all()
{
	test_breadth_search_new();
	test_breadth_search_empty_frontier_fails();
	test_breadth_search_from_to_same();
	test_breadth_search_one_shortest_path();
	test_breadth_search_single_segment();
}