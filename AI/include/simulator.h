#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "environment.h"

typedef struct simulator simulator;
struct simulator {
	int foo;
};

simulator *simulator_new();
void simulator_free(simulator *this);

#endif /* _SIMULATOR _H */
