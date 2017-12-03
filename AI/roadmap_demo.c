#include "roadmap.h"
#include "romania.h"

int main() {
	printf("Roadmap demo\n");
	roadmap *romania = roadmap_new(routes_of_romania);

	int city_count = roadmap_city_count(romania);
	printf("Romania has %i cities\n", city_count);

	for (int i = 0; i < city_count; i++) {
		printf("%02d. %s\n", i + 1, romania->city_names[i]);
	}

	roadmap_free(romania);
	return 0;
}