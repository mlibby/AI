#include "roadmap.h"
#include "romania.h"
#include "tree_search.h"

int main(int argc, char* argv[]) {
	printf("Map Search\n");

	roadmap *romania = roadmap_new(routes_of_romania);

	printf("Here is the list of cities:\n");
	int city_count = romania->city_count;
	for (int i = 0; i < city_count; i++) {
		printf("%i. %s\n", i + 1, romania->city_names[i]);
	}

	int starting_index = get_numeric_input("Start at #: ", 1, city_count) - 1;
	int ending_index = get_numeric_input("End at #: ", 1, city_count) - 1;

	char *starting_city = romania->city_names[starting_index];
	char *ending_city = romania->city_names[ending_index];

	printf("Finding route from %s to %s...\n", starting_city, ending_city);

	tree_search *search = tree_search_new(romania->graph);
	tree_search_search(search, starting_city, ending_city);

	printf("Search took %f seconds\n", difftime(search->end_time, search->start_time));

	tree_search_free(search);
	roadmap_free(romania);
	return 0;
}