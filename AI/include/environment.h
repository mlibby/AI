#ifndef _ENVIRONMENT_H
#define _ENVIRONMENT_H

#include "graph.h"

typedef struct environment Environment;
struct environment {
	Graph *graph;
};

Environment *environment_new(Graph *graph);
void environment_free(Environment *this);

#endif /* _ENVIRONMENT_H */

