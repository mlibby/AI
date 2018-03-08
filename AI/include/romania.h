#ifndef _ROMANIA_H
#define _ROMANIA_H

#include <stdlib.h>
#include "ai_common.h"
#include "graph.h"

graph_segment cities_of_romania[] = {
	{ "Arad", "Sibiu", 140, GRAPH_SEGMENT_UNDIRECTED},
	{ "Arad", "Timisoara", 118, GRAPH_SEGMENT_UNDIRECTED },
	{ "Arad",  "Zerind", 75, GRAPH_SEGMENT_UNDIRECTED },
	{ "Bucharest", "Fagaras", 211, GRAPH_SEGMENT_UNDIRECTED },
	{ "Bucharest", "Giurgiu", 90, GRAPH_SEGMENT_UNDIRECTED },
	{ "Bucharest", "Pitesti", 101, GRAPH_SEGMENT_UNDIRECTED },
	{ "Bucharest","Urziceni", 85, GRAPH_SEGMENT_UNDIRECTED },
	{ "Craiova", "Drobeta", 120, GRAPH_SEGMENT_UNDIRECTED },
	{ "Craiova", "Pitesti", 138, GRAPH_SEGMENT_UNDIRECTED },
	{ "Craiova", "Rimnica Vilcea", 146, GRAPH_SEGMENT_UNDIRECTED },
	{ "Drobeta", "Mehadia", 75, GRAPH_SEGMENT_UNDIRECTED },
	{ "Eforie", "Hirsova", 86, GRAPH_SEGMENT_UNDIRECTED },
	{ "Fagaras", "Sibiu", 99, GRAPH_SEGMENT_UNDIRECTED },
	{ "Hirsova", "Urziceni", 98, GRAPH_SEGMENT_UNDIRECTED },
	{ "Iasi", "Neamt", 87, GRAPH_SEGMENT_UNDIRECTED },
	{ "Iasi", "Vaslui", 92, GRAPH_SEGMENT_UNDIRECTED },
	{ "Lugoj", "Mehadia", 70,  GRAPH_SEGMENT_UNDIRECTED },
	{ "Lugoj", "Timisoara", 111, GRAPH_SEGMENT_UNDIRECTED },
	{ "Oradea", "Sibiu", 151, GRAPH_SEGMENT_UNDIRECTED },
	{ "Oradea", "Zerind", 71, GRAPH_SEGMENT_UNDIRECTED },
	{ "Pitesti","Rimnica Vilcea" , 97, GRAPH_SEGMENT_UNDIRECTED },
	{ "Rimnica Vilcea",  "Sibiu", 80, GRAPH_SEGMENT_UNDIRECTED },
	{ "Urziceni",  "Vaslui", 142, GRAPH_SEGMENT_UNDIRECTED },
	{ NULL, NULL, 0, 0 }
};

#endif