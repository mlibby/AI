#include "fifo.h"

int main(int argc, char* argv[]) {
	printf("FIFO Queue Demo\n");

	queue *fifo = fifo_new();
	
	printf("Creating some data...\n");
	char *first = strdup("first");
	char *second = strdup("second");
	char *third = strdup("third");

	printf("Adding elements to queue...\n");
	fifo_add(fifo, first);
	fifo_add(fifo, second);
	fifo_add(fifo, third);

	printf("The FIFO queue has %i elements\n", fifo->count);

	int i = 1;
	while (fifo->count > 0)
	{
		printf("Removing item from queue\n");
		char *tmp = fifo_remove(fifo);
		printf("Item #%i: %s\n", i++, tmp);
	}

	printf("Queue is empty\n");

	return 0;
}