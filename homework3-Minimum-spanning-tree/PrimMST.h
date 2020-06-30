#pragma once

#include "Graph.h"
#include "PriorityQueue.h"

class PrimMST
{
private:
	Graph* graph;
	vector<Edge> path;

public:
	PrimMST(const Graph mGraph) {
		graph = new Graph(mGraph);
	}


public:
	int calculateMST();
	vector<Edge> getPathMST();
};

