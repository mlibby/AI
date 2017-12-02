#include "romania.h"
#include "sort.h"

int main(int argc, char* argv[]) {
	printf("Romania Map Search\n");

	graph *romania = romania_build_graph();

	int city_count = romania_get_city_count(romania);
	char **cities = romania_get_city_names(romania);

	printf("Here is the list of cities:\n");
	for (int i = 0; i < city_count; i++) {
		printf("%i. %s\n", i + 1, cities[i]);
	}

	int starting_index = get_numeric_input("Start at #: ", 1, city_count) - 1;
	int ending_index = get_numeric_input("End at #: ", 1, city_count) - 1;

	char *starting_city = cities[starting_index];
	char *ending_city = cities[ending_index];

	printf("Finding route from %s to %s...\n", starting_city, ending_city);

	romania_free(romania);
	return 0;
}