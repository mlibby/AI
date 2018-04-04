#include "agent.h"
#include "ai_common.h"
#include "test.h"
#include "test_agent.h"

void
test_agent_all()
{
	Agent *agent = agent_new("TEST");
	
	char *action = agent_get_action(agent, "0_0,DIRTY");
	ASSERT(0 == strcmp(action, "SUCK"));
	
	action = agent_get_action(agent, "0_0,CLEAN");
	ASSERT(0 == strcmp(action, "RIGHT"));

	action = agent_get_action(agent, "1_0,DIRTY");
	ASSERT(0 == strcmp(action, "SUCK"));

	action = agent_get_action(agent, "1_0,CLEAN");
	ASSERT(0 == strcmp(action, "LEFT"));

	action = agent_get_action(agent, "FOO,BAR");
	ASSERT(0 == strcmp(action, ""));

	agent_free(agent);
}