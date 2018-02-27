#include <stdio.h>
#include "test.h"
#include "test_fifo.h"

int tests_passed = 0;
int tests_run = 0;

int main(int argc, char **argv)
{
	test_fifo_all();
	printf("%d/%d tests passed\n", tests_passed, tests_run);
	return 0;
}