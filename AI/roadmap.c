#include "roadmap.h"

roadmap *roadmap_new(char *routes[][4])
{
	roadmap *this = (roadmap *)malloc(sizeof(roadmap));

	int n = 0;
	char **route;
	route = (char **)routes[n];
	while (route[0] != NULL) {
		n++;
		route = (char **)routes[n];
	}

	printf("Found %d routes\n", n);

	return this;
}

int roadmap_city_count(roadmap *this)
{
	return 0;
}

void roadmap_free(roadmap *this) {
	free(this);
}