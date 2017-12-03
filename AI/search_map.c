#include "roadmap.h"
#include "romania.h"

int main(int argc, char* argv[]) {
	printf("Map Search\n");

	roadmap *romania = roadmap_new(routes_of_romania);

	printf("Here is the list of cities:\n");
	int city_count = roadmap_city_count(romania);
	for (int i = 0; i < city_count; i++) {
		printf("%i. %s\n", i + 1, romania->city_names[i]);
	}

	int starting_index = get_numeric_input("Start at #: ", 1, city_count) - 1;
	int ending_index = get_numeric_input("End at #: ", 1, city_count) - 1;

	char *starting_city = romania->city_names[starting_index];
	char *ending_city = romania->city_names[ending_index];

	printf("Finding route from %s to %s...\n", starting_city, ending_city);

	roadmap_free(romania);
	return 0;
}