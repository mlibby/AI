#include <stdlib.h>
#include "simulator.h"

simulator 
*simulator_new()
{
	simulator *this = malloc(sizeof(simulator));
	return this;
}

void
simulator_free(simulator *this)
{
	free(this);
}