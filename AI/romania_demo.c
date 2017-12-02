#include "roadmap.h"

char *edges[][4] = {
	{ "Arad", "140", "Sibiu", "0" },
	{ "Arad", "118", "Timisoara", "1" },
	{ "Arad", "75", "Zerind", "1" },
	{ "Bucharest", "211", "Fagaras", "1" },
	{ "Bucharest", "90", "Giurgiu", "1" },
	{ "Bucharest", "101", "Pitesti", "1" },
	{ "Bucharest", "85", "Urziceni", "1" },
	{ "Craiova", "120", "Drobeta", "1" },
	{ "Craiova", "138", "Pitesti", "1" },
	{ "Craiova", "146", "Rimnica Vilcea", "1" },
	{ "Drobeta", "75", "Mehadia", "1" },
	{ "Eforie", "86", "Hirsova", "1" },
	{ "Fagaras", "99", "Sibiu", "1" },
	{ "Hirsova", "98", "Urziceni", "1" },
	{ "Iasi", "87", "Neamt", "1" },
	{ "Iasi", "92", "Vaslui", "1" },
	{ "Lugoj", "70", "Mehadia", "1" },
	{ "Lugoj", "111", "Timisoara", "1" },
	{ "Oradea", "151", "Sibiu", "1" },
	{ "Oradea", "71", "Zerind", "1" },
	{ "Pitesti", "97", "Rimnica Vilcea" , "1" },
	{ "Rimnica Vilcea", "80", "Sibiu", "1" },
	{ "Urziceni", "142", "Vaslui", "1" },
	{ NULL, NULL, NULL, NULL }
};

int main() {
	printf("Romania roadmap demo\n");
	roadmap *romania = roadmap_new(edges);

	printf("Romania has %i cities\n", roadmap_city_count(romania));

	roadmap_free(romania);
	return 0;
}