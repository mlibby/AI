#include "test.h"
#include "test_simulator.h"
#include "agent.h"
#include "environment.h"
#include "graph.h"
#include "simulator.h"

void
test_simulator_add_and_get_agent()
{
	Graph *grid = graph_create_grid(2, 1);
	Environment *environment = environment_new(grid);
	Simulator *simulator = simulator_new(10);
	simulator_set_environment(simulator, environment);

	Agent *agent = agent_new("ReflexVacuum");
	simulator_add_agent(simulator, agent, "0_0");
	ASSERT(NULL != simulator_get_agent(simulator, "ReflexVacuum"));
	ASSERT(NULL == simulator_get_agent(simulator, "FOOBAR"));

	agent_free(agent);
	simulator_free(simulator);
	environment_free(environment);
	graph_free(grid);
}

void
test_simulator_new()
{
	Simulator *simulator = simulator_new(10);
	ASSERT(10 == simulator->max_turns);
	simulator_free(simulator);
}

void
test_simulator_set_environment()
{
	Graph *grid = graph_create_grid(2, 1);
	Environment *environment = environment_new(grid);

	Simulator *simulator = simulator_new(10);
	simulator_set_environment(simulator, environment);
	ASSERT(environment == simulator->environment);

	/* IGNORE environment setting after first one */
	Environment *environment2 = environment_new(grid);
	simulator_set_environment(simulator, environment2);
	ASSERT(environment == simulator->environment);

	simulator_free(simulator);
	environment_free(environment);
	environment_free(environment2);
	graph_free(grid);
}

void
test_simulator_all()
{
	test_simulator_add_and_get_agent();
	test_simulator_new();
	test_simulator_set_environment();
}