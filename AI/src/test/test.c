#include "test.h"
#include "test_ai_common.h"
#include "test_fifo.h"
#include "test_graph.h"

int tests_passed = 0;
int tests_run = 0;

int main(int argc, char **argv)
{
	test_fifo_all();
	test_graph_all();
	test_ai_common_all();
	printf("%d/%d tests passed\n", tests_passed, tests_run);
	return 0;
}