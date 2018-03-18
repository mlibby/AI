#include "test_simulator.h"
#include "simulator.h"

void
test_simulator_all()
{
	graph *grid = graph_new();
	environment *env = environment_new(grid);
	simulator *sim = simulator_new(env);
	simulator_free(sim);
	environment_free(env);
	graph_free(grid);
}