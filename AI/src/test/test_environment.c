#include <stdio.h>
#include "test.h"
#include "test_environment.h"
#include "environment.h"

void
test_environment_new()
{
	graph *graph = graph_new();
	environment *env = environment_new(graph);
	ASSERT(graph == env->graph);
	environment_free(env);
	graph_free(graph);
}

void 
test_environment_all()
{
	test_environment_new();
}
