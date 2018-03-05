#include "test.h"
#include "test_ai_common.h"
#include "test_fifo.h"
#include "test_graph.h"
#include "test_lifo.h"
#include "test_search_node.h"
#include "test_tree_search.h"

int tests_passed = 0;
int tests_run = 0;

int main(int argc, char **argv)
{
	test_ai_common_all();
	test_fifo_all();
	test_graph_all();
	test_lifo_all();
	test_search_node_all();
	test_tree_search_all();

	printf("%d/%d tests passed\n", tests_passed, tests_run);
	return 0;
}