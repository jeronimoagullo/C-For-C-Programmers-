#include "Graph.h"

/*************************************************************************************/
/******************************** Edge class *****************************************/
/*************************************************************************************/
Edge::Edge(int ID, int w) {
	nodeID = ID;
	weight = w;
}

int Edge::getNodeID(){
	return nodeID;
}

void Edge::setWeight(int value){
	weight = value;
	cout << "set the value: " << weight << endl;
}

int Edge::getWeight(){
	return weight;
}


ostream& operator<<(ostream &out, const Edge& e)
{
	out << "(" << e.nodeID << "), " << e.weight << " -> ";
	return out;
}


/*************************************************************************************/
/******************************* Graph class *****************************************/
/*************************************************************************************/
Graph::Graph():numV(0),density(0), minCost(0),maxCost(1000) { }

Graph::Graph(int n, int d, int miniCost, int maxiCost) {
	numV = n;
	density = d;
	minCost = miniCost;
	maxCost = maxiCost;

	// create a random graph
	for (int i = 0; i < numV; i++) {
		list<Edge> v;
		verteces.push_back(v);
	}

	srand(time(0));
	for (int i = 0; i < numV; i++) {
		for (int j = i; j < numV; j++) {
			if (prob() < density) {
				int value = minCost +  (rand()) / ((RAND_MAX / (maxCost - minCost))) + 0.5;
				this->add(i, j, value);
			}
		}
	}

	cout << "Created a graph of degree: " << verteces.size() << endl;
}

Graph::Graph(const Graph& oldGraph){
	numV = oldGraph.numV;
	numE = oldGraph.numE;
	density = oldGraph.density;
	minCost = oldGraph.minCost;
	maxCost = oldGraph.maxCost;
	verteces = oldGraph.verteces;
}

Graph::~Graph(){
	verteces.clear();
	cout << "the graph was deleted" << endl;
}

inline int Graph::prob(){
	return rand() % MAX_PROB;
}


// returns the number of vertices in the graph
int Graph::V() {
	return numV;
}

// returns the number of edges in the graph
int Graph::E() {
	return numE;
}

// tests whether there is an edge from node x to node y.
bool Graph::adjacent(int x, int y) {

	for (auto i = verteces[x].begin(); i != verteces[x].end(); ++i) {
		if (i->getNodeID() == y) {
			return true;
		}
	}

	return false;
}

// lists all nodes y such that there is an edge from x to y
vector <int>  Graph::neighbors(int x) {
	vector<int> list;

	for (auto it = verteces[x].begin(); it != verteces[x].end(); ++it) {
		list.push_back(it->getNodeID());
	}

	return list;
}

// adds to G the edge from x to y, if it is not there
void Graph::add(int x, int y, int value){
	if (x == y) {
		return;
	}
	if (x < numV && y < numV) {
		verteces[x].push_back(Edge(y, value));
		verteces[y].push_back(Edge(x, value));
		numE++;
	}else
		cout << "The edge " << x << "," << y << " cannot exist" << endl;
}

// removes the edge from x to y, if it is there.
void Graph::remove(int x, int y){

	bool success = false;

	for (auto i = verteces[x].begin(); i != verteces[x].end(); ++i) {
		if (i->getNodeID() == y) {
			verteces[x].erase(i);
			success = true;
			break;
		}
	}

	for (auto j = verteces[x].begin(); j != verteces[x].end(); ++j) {
		if (j->getNodeID() == x) {
			verteces[y].erase(j);
			success = true;
			break;
		}
	}

	if (success) {
		numE--;
	}else {
		cout << "Error. The edge: " << x << "," << y << " does not exist" << endl;
	}
}

// returns the value associated to the edge(x, y).
int Graph::get_edge_value(int x, int y){

	for (auto i = verteces[x].begin(); i != verteces[x].end(); ++i) {
		if (i->getNodeID() == y) {
			return i->getWeight();
		}
	}

	for (auto j = verteces[x].begin(); j != verteces[x].end(); ++j) {
		if (j->getNodeID() == x) {
			return j->getWeight();
		}
	}
	cout << "Error. The edge: " << x << "," << y << " does not exist" << endl;
	return 0.0f;
}

// sets the value associated to the edge(x, y) to v.
void Graph::set_edge_value(int x, int y, int value){

	bool success = false;

	for (auto e = verteces[x].begin(); e != verteces[x].end(); ++e){
		if (e->getNodeID() == y) {
			e->setWeight(value);
			success = true;
		}
	}

	for (auto e = verteces[y].begin(); e != verteces[y].end(); ++e) {
		if (e->getNodeID() == x) {
			e->setWeight(value);
			success = true;
		}
	}
	
	if (success == false) {
		cout << "Error. The edge: " << x << "," << y << " does not exist" << endl;
	}
}

// print the graph
void Graph::print(){
	cout << endl << "************************ printing Graph ************************" << endl;

	int i = 0;
	for (auto v : verteces) {
		cout << "vertex No " << i << ": ";
		for (auto elm : v)
			cout << elm;
		cout << "###" << endl;
		i++;
	}
	cout << "****************************************************************" << endl;
	cout << endl;
}

