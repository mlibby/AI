#include "sort.h"

void sort_char_in_place(int list_size, char **list) {
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