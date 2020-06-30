/****************************************************************************************************/
/*                                      											                */
/* Author:	Jerónimo Agulló															                */
/* Date:	06/06/2020															                    */
/* Brief:	This class is an implementation of a represention of a graph. This class uses the       */
/*			list representation. Moreover, the Graph class uses a Edge class which allows to		*/
/*			indicate the weight of each edge														*/
/*                                      											                */
/****************************************************************************************************/
#pragma once

#include <iostream>
#include <fstream>
#include<ctime>
#include <list>
#include <vector>

using namespace std;

class Edge {
public:
	// constructors
	Edge() :nodeID(0), weight(0) {};
	Edge(int ID, int w);

	friend ostream& operator<<(ostream& out, const Edge& e);
	int getNodeID();
	void setWeight(int value);
	int getWeight();

private:
	int nodeID;
	int weight;
};

class Graph
{
private:
	int numV = 0;
	int numE = 0;
	int density = 0;
	const int MAX_PROB = 100;
	float minCost = 0.0f;
	float maxCost = 0.0f;
	vector<list<Edge>> verteces;


public:
	// default constructor
	Graph();
	// constructor with number of nodes, density and cost
	Graph(int n, int d, int miniCost, int maxiCost);
	// copy constructor
	Graph(const Graph&);
	// reading from txt file constructor
	Graph(const string fileName);

	// destructor
	~Graph();

	// returns the number of vertices in the graph
	int V();
	// returns the number of edges in the graph
	int E();
	// tests whether there is an edge from node x to node y.
	bool adjacent(int x, int y);
	// lists all nodes y such that there is an edge from x to y
	vector <int> neighbors(int x);
	// adds to G the edge from x to y, if it is not there
	void add(int x, int y, int value);
	// removes the edge from x to y, if it is there.
	void remove(int x, int y);
	// returns the value associated to the edge(x, y).
	int get_edge_value(int x, int y);
	// sets the value associated to the edge(x, y) to v.
	void set_edge_value(int x, int y, int value);
	// print the graph
	void print();
	// calculate a random probability between 0 and 100
	inline int prob();
};

