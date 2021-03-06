#include "test.h"
#include "test_agent.h"
#include "test_ai_common.h"
#include "test_breadth_search.h"
#include "test_environment.h"
#include "test_graph.h"
#include "test_queue.h"
#include "test_search_node.h"
#include "test_simulator.h"

int tests_passed = 0;
int tests_run = 0;

int main(int argc, char **argv)
{
	test_ai_common_all();
	test_agent_all();
	test_breadth_search_all();
	test_environment_all();
	test_graph_all();
	test_queue_all();
	test_search_node_all();
	test_simulator_all();

	printf("%d/%d tests passed\n", tests_passed, tests_run);
	return 0;
}