#include "roadmap.h"
#include "romania.h"

int main() {
	printf("Roadmap demo\n");
	roadmap *romania = roadmap_new(routes_of_romania);

	printf("Romania has %i cities\n", romania->city_count);
	for (int i = 0; i < romania->city_count; i++) {
		printf("%02d. %s\n", i + 1, romania->city_names[i]);
	}

	roadmap_free(romania);
	return 0;
}