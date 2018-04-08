#include <stdio.h>
#include "test.h"
#include "test_environment.h"
#include "environment.h"

void
test_environment_new()
{
	Graph *graph = graph_new();
	Environment *env = environment_new(graph);
	ASSERT(graph == env->graph);
	environment_free(env);
	graph_free(graph);
}

void
test_environment_states()
{
	Graph *grid = graph_create_grid(2, 1);
	Environment *environment = environment_new(grid);
	environment_add_state(environment, "CLEAN");
	environment_add_state(environment, "DIRTY");

	ASSERT(2 == environment_count_states(environment));

	environment_free(environment);
	graph_free(grid);
}

void 
test_environment_all()
{
	test_environment_new();
	test_environment_states();
}
