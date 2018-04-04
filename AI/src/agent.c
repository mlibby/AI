#include <stdlib.h>
#include <string.h>
#include "agent.h"

Agent
*agent_new(char const *name)
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

char
*agent_get_action(Agent *this, char const *percept)
{
	if (0 == strcmp("0_0,DIRTY", percept)) {
		return "SUCK";
	}
	if (0 == strcmp("0_0,CLEAN", percept)) {
		return "RIGHT";
	}
	if (0 == strcmp("1_0,DIRTY", percept)) {
		return "SUCK";
	}
	if (0 == strcmp("1_0,CLEAN", percept)) {
		return "LEFT";
	}
	return "";
}
