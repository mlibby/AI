#ifndef _ENVIRONMENT_H
#define _ENVIRONMENT_H

#include "graph.h"
#include "queue.h"

typedef struct environment Environment;
struct environment {
	Graph *graph;
	Queue *states;
};

Environment *environment_new(Graph *graph);
void environment_free(Environment *this);

void environment_add_state(Environment *this, const char *state);
int environment_count_states(Environment *this);

#endif /* _ENVIRONMENT_H */

