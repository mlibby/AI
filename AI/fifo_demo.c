#include "fifo.h"

int main(int argc, char* argv[]) {
	printf("FIFO Queue Demo\n");

	fifo *fifo = fifo_new();
	
	printf("Creating some data...\n");
	char *first = strdup("first");
	char *second = strdup("second");
	char *third = strdup("third");

	printf("Adding elements to queue...\n");
	fifo_add(fifo, first);
	fifo_add(fifo, second);
	fifo_add(fifo, third);

	//printf("The FIFO queue has %d elements\n", fifo->count);

	int i = 1;
	while (fifo_has_items(fifo))
	{
		printf("Removing item from queue\n");
		char *tmp = fifo_remove(fifo);
		printf("Item #%i: %s\n", i, tmp);
		i++;
	}

	printf("Queue is empty\n");

	fifo_free(fifo);
	free(first);
	free(second);
	free(third);

	return 0;
}