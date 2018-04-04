#include <stdlib.h>
#include <string.h>
#include "simulator.h"

typedef struct agent_location AgentLocation;
struct agent_location {
	Agent *agent;
	char *location;
};

Simulator
*simulator_new(int max_turns)
{
	Simulator *this = malloc(sizeof(Simulator));
	this->max_turns = max_turns;
	this->environment = NULL;
	this->agents = queue_new();
	return this;
}

void
simulator_free(Simulator *this)
{
	QueueItem *queue_item = this->agents->head;
	while (queue_item != NULL) {
		AgentLocation *agent_location = (AgentLocation*)queue_item->data;
		free(agent_location->location);
		free(agent_location);
		queue_item = queue_item->next;
	}
	queue_free(this->agents);
	free(this);
}

void
simulator_add_agent(Simulator *this, Agent *agent, char const *location)
{
	AgentLocation *agent_location = malloc(sizeof(AgentLocation));
	agent_location->agent = agent;
	agent_location->location = strdup(location);
	queue_add(this->agents, agent_location);
}

Agent 
*simulator_get_agent(Simulator *this, char const *name)
{
	QueueItem *queue_item = this->agents->head;
	while (queue_item != NULL) {
		AgentLocation *agent_location = (AgentLocation*)queue_item->data;
		if (0 == strcmp(name, agent_location->agent->name)) {
			return agent_location->agent;
		}
	}
	return NULL;
}

void
simulator_set_environment(Simulator *this, Environment *environment)
{
	if (NULL == this->environment) {
		this->environment = environment;
	}
}