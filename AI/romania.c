#include "romania.h"
#include "roadmap.h"

#define CITY_COUNT 20
#define PAIR_COUNT 23

char *edges[PAIR_COUNT][3] = {
	{"Arad", "140", "Sibiu"},
	{"Arad", "118", "Timisoara"},
	{"Arad", "75", "Zerind"},
	{"Bucharest", "211", "Fagaras"},
	{"Bucharest", "90", "Giurgiu"},
	{"Bucharest", "101", "Pitesti"},
	{"Bucharest", "85", "Urziceni"},
	{"Craiova", "120", "Drobeta"},
	{"Craiova", "138", "Pitesti"},
	{"Craiova", "146", "Rimnica Vilcea"},
	{"Drobeta", "75", "Mehadia"},
	{"Eforie", "86", "Hirsova"},
	{"Fagaras", "99", "Sibiu"},
	{"Hirsova", "98", "Urziceni"},
	{"Iasi", "87", "Neamt"},
	{"Iasi", "92", "Vaslui"},
	{"Lugoj", "70", "Mehadia"},
	{"Lugoj", "111", "Timisoara"},
	{"Oradea", "151", "Sibiu"},
	{"Oradea", "71", "Zerind"},
	{"Pitesti", "97", "Rimnica Vilcea"},
	{"Rimnica Vilcea", "80", "Sibiu"},
	{"Urziceni", "142", "Vaslui"}
};

graph *romania_build_graph()
{
	graph *romania = graph_new(CITY_COUNT);

	for (int i = 0; i < PAIR_COUNT; i++) {
		char *city_one = edges[i][0];
		char *city_two = edges[i][2];

		int distance = 0;
		int parsed = sscanf(edges[i][1], "%d", &distance);

		if (parsed)
		{
			graph_add_pair(romania, city_one, city_two, distance);
			graph_add_pair(romania, city_two, city_one, distance);
		}
	}

	return romania;
}

char **romania_get_city_names(graph *romania) {
	char **cities = (char **)malloc(sizeof(char*) * romania->vertex_count);

	for (int i = 0; i < romania->vertex_count; i++) {
		cities[i] = strdup(romania->vertices[i]->name);
	}

	sort_char_in_place(romania->vertex_count, cities);
	return cities;
}

int romania_get_city_count(graph *romania) {
	return romania->vertex_count;
}

void romania_free_city_names(graph *romania, char **cities) {
	for (int i = 0; i < romania->vertex_count; i++) {
		free(cities[i]);
	}
	free(cities);
}
