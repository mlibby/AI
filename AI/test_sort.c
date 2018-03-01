#include <stdlib.h>
#include "test.h"
#include "test_sort.h"
#include "sort.h"

void
test_sort_all()
{
	int city_count = 6;
	char **cities = malloc(sizeof(char*) * city_count);

	cities[0] = strdup("alpha");
	cities[1] = strdup("zebra");
	cities[2] = strdup("tango");
	cities[3] = strdup("bravo");
	cities[4] = strdup("foxtrot");
	cities[5] = strdup("charlie");

	sort_char_in_place(city_count, cities);

	ASSERT(0 == strcmp("alpha", cities[0]));
	ASSERT(0 == strcmp("bravo", cities[1]));
	ASSERT(0 == strcmp("charlie", cities[2]));
	ASSERT(0 == strcmp("foxtrot", cities[3]));
	ASSERT(0 == strcmp("tango", cities[4]));
	ASSERT(0 == strcmp("zebra", cities[5]));

	for (int i = 0; i < city_count; i++) {
		free(cities[i]);
	}
	free(cities);
}