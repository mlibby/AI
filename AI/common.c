#include "common.h"

int get_numeric_input(char *prompt, int min, int max) {
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