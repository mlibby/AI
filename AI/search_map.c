#include "romania.h"
#include "sort.h"

int main(int argc, char* argv[]) {
	printf("Romania Map Search\n");

	graph *romania = build_graph_romania();

	int city_count = romania->vertex_count;
	char **cities = (char **)malloc(sizeof(char*) * city_count);

	for (int i = 0; i < city_count; i++) {
		cities[i] = strdup(romania->vertices[i]->name);
	}

	sort_char_in_place(city_count, cities);

	printf("Here is the list of cities:\n");
	for (int i = 0; i < city_count; i++) {
		printf("%i. %s\n", i + 1, cities[i]);
	}

	int starting_index = get_numeric_input("Start at #: ", 1, city_count) - 1;
	int ending_index = get_numeric_input("End at #: ", 1, city_count) - 1;

	char *starting_city = cities[starting_index];
	char *ending_city = cities[ending_index];

	printf("Finding route from %s to %s...\n", starting_city, ending_city);

	return 0;
}