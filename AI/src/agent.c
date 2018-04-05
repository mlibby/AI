#include <stdlib.h>
#include <string.h>
#include "agent.h"

Agent*
agent_new(const char *name)
{
	Agent *this = malloc(sizeof(Agent));
	this->name = strdup(name);
	return this;
}

void
agent_free(Agent *this)
{
	free(this->name);
	free(this);
}

const char*
agent_get_action(Agent *this, const char *percept)
{
	char *action = "";
	if (0 == strcmp("0_0,DIRTY", percept)) {
		action = "SUCK";
	}
	if (0 == strcmp("0_0,CLEAN", percept)) {
		action = "RIGHT";
	}
	if (0 == strcmp("1_0,DIRTY", percept)) {
		action = "SUCK";
	}
	if (0 == strcmp("1_0,CLEAN", percept)) {
		action = "LEFT";
	}
	return action;
}
