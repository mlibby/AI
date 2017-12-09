#include "sort.h"

int main(int argc, char* argv[]) {
	printf("Sort Demo\n");

	int city_count = 6;
	char **cities = malloc(sizeof(char*) * city_count);

	cities[0] = strdup("alpha");
	cities[1] = strdup("zebra");
	cities[2] = strdup("tango");
	cities[3] = strdup("bravo");
	cities[4] = strdup("foxtrot");
	cities[5] = strdup("charlie");

	printf("Unsorted List:\n");
	for (int i = 0; i < city_count; i++) {
		printf("%i. %s\n", i + 1, cities[i]);
	}

	sort_char_in_place(city_count, cities);

	printf("Sorted List:\n");
	for (int i = 0; i < city_count; i++) {
		printf("%i. %s\n", i + 1, cities[i]);
	}
}