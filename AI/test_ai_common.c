#include <stdlib.h>
#include <stdio.h>
#include "ai_common.h"
#include "test.h"
#include "test_ai_common.h"

void
test_sort()
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

static int calls_to_getline;

extern long int
mock_getline(char **lineptr, long unsigned int *n, struct _IO_FILE *stream)
{
	calls_to_getline++;
	switch (calls_to_getline) {
	case 1:
		*lineptr = strdup("5");
		return 2;
	case 2:
		*lineptr = strdup("11");
		return 3;
	case 3:
		*lineptr = strdup("0");
		return 2;
	case 4:
		*lineptr = strdup("1");
		return 2;
	default:
		return 0;
	}
}

static char mock_printf_string[255];

int
mock_printf(const char* format, ...)
{
	strcat(mock_printf_string, format);
	return 1;
}

void test_get_numeric_input()
{
	calls_to_getline = 0;

	mock_printf_string[0] = 0;
	int x = get_numeric_input("Enter #\n", 1, 10, mock_getline, mock_printf);
	ASSERT(5 == x);
	ASSERT(0 == strcmp("%s", mock_printf_string));

	mock_printf_string[0] = 0;
	x = get_numeric_input("Enter #\n", 1, 10, mock_getline, mock_printf);
	ASSERT(1 == x);
	ASSERT(0 == strcmp("%sInvalid input\n%sInvalid input\n%s", mock_printf_string));
}

void
test_ai_common_all()
{
	test_sort();
	test_get_numeric_input();
}