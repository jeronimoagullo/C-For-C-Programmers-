/****************************************************************************************************/
/*                                      											                */
/* Author:	Jerónimo Agulló															                */
/* Date:	06/06/2020															                    */
/* Brief:	This class is an implementation of a Shortest path algorithm based on                   */
/*			the Dijkstra algorithm                                                                  */
/*                                      											                */
/****************************************************************************************************/
#pragma once
#include "Graph.h"
#include "PriorityQueue.h"

class ShortestPath
{

public:
	// find the shortest path from iniVertex to endVertex
	std::vector<int> path(Graph& graph, int u, int w);

	// return the path cost associated with the shortest path
	int pathSize(Graph& graph, int iniVertex, int endVertex);

private:
	const int INF = INT_MAX;
	// algorithm to calculate the shortest path
	int dijkstra(Graph& graph, int u, int w);

	// In order to construct the shorest path, store each node's previous node
	std::vector<int> traces;

};

