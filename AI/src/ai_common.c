#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ai_common.h"

void
sort_char_in_place(int list_size, char **list) {
	for (int i = 0; i < list_size; i++) {
		for (int j = i + 1; j < list_size; j++) {
			if (0 < strcasecmp(list[i], list[j])) {
				char *tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

int
get_numeric_input(const char *prompt, int min, int max, ptr_getline getline, ptr_printf printf)
{
	int result = -1;
	char *line = NULL;
	size_t n;
	ssize_t chars_read = -1;

	while (chars_read < 2 || result < min || result > max) {
		printf("%s", prompt);
		chars_read = getline(&line, &n, stdin);
		sscanf(line, "%d", &result);
		free(line);
		line = NULL;
		if (result < min || result > max) {
			printf("Invalid input\n");
		}
	}

	return result;
}