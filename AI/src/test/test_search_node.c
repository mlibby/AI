#include "test.h"
#include "test_search_node.h"
#include "search_node.h"

void
test_search_node_new()
{
	SearchNode *parent = search_node_new("Parent", "", 0, NULL);
	SearchNode *node = search_node_new("Node", "Action", 123, parent);
	ASSERT(0 == strcmp("Node", node->state));
	ASSERT(0 == strcmp("Action", node->action));
	ASSERT(123 == node->path_cost);
	ASSERT(parent == node->parent);

	search_node_free(node);
	search_node_free(parent);
}

void
test_search_node_all()
{
	test_search_node_new();
}