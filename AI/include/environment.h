#ifndef _ENVIRONMENT_H
#define _ENVIRONMENT_H

#include "graph.h"

typedef struct environment environment;
struct environment {
	graph *graph;
};

environment *environment_new(graph *graph);
void environment_free(environment *this);

#endif /* _ENVIRONMENT_H */

