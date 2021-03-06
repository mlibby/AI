#include <stdio.h>
#include <sys/time.h>
#include "ai_common.h"
#include "breadth_search.h"
#include "graph.h"
#include "queue.h"
#include "romania.h"

int main(int argc, char* argv[]) {
	printf("Find a path in Romania\n");

	Graph *romania = graph_create(cities_of_romania);

	printf("Here is the list of cities:\n");
	int city_count = graph_vertex_count(romania);
	char **cities = graph_get_vertex_names(romania);
	sort_char_in_place(city_count, cities);
	for (int i = 0; i < city_count; i++) {
		printf("%i. %s\n", i + 1, cities[i]);
	}

	int starting_index = get_numeric_input("Start at #: ", 1, city_count, getline, printf) - 1;
	int ending_index = get_numeric_input("End at #: ", 1, city_count, getline, printf) - 1;

	char *starting_city = cities[starting_index];
	char *ending_city = cities[ending_index];

	printf("Finding route from %s to %s...\n", starting_city, ending_city);

	BreadthSearch *search = breadth_search_new(romania);

	struct timeval start;
	gettimeofday(&start, NULL);

	SearchNode *solution = breadth_search_search(search, starting_city, ending_city);

	struct timeval stop;
	gettimeofday(&stop, NULL);
	
	printf("Search took %lu usec\n", stop.tv_usec - start.tv_usec);

	printf("Nodes used: %d\n", queue_count_items(search->nodes));

	Queue *path = stack_new();
	while (solution) {
		queue_add(path, solution->state);
		solution = solution->parent;
	}

	while (queue_has_items(path)) {
		printf("From: %s\n", (char *)queue_remove(path));
	}

	breadth_search_free(search);
	graph_free(romania);
}