#ifndef _AGENT_H
#define _AGENT_H

typedef struct agent Agent;

struct agent {
	int id;
	char *name;
};

Agent *agent_new(const char *name);
void agent_free(Agent *this);

const char *agent_get_action(Agent *this, const char *percept);

#endif /* _AGENT_H */