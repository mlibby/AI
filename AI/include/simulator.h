#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "agent.h"
#include "environment.h"
#include "queue.h"

typedef struct simulator Simulator;
struct simulator {
	int max_turns;
	Environment *environment;
	Queue *agents;
};

Simulator *simulator_new(int max_turns);
void simulator_free(Simulator *this);

void simulator_set_environment(Simulator *this, Environment *environment);
void simulator_add_agent(Simulator *this, Agent *agent, const char *location);
Agent *simulator_get_agent(Simulator *this, const char *name);

#endif /* _SIMULATOR _H */
