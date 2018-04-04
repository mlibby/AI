#ifndef _AGENT_H
#define _AGENT_H

typedef struct agent Agent;

struct agent {
	int id;
	char *name;
};

Agent *agent_new(char const *name);
void agent_free(Agent *this);

char *agent_get_action(Agent *this, char const *percept);

#endif /* _AGENT_H */