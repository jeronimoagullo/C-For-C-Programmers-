// homework3_minimum_spanning_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "PrimMST.h"

int main()
{

    Graph graph("SampleTestData.txt");
    graph.print();

    PrimMST mst = PrimMST(graph);
    int cost = mst.calculateMST();
    vector<Edge> path = mst.getPathMST();

    cout << "The cost of the MST: " << cost << endl;
    cout << "The path: " << endl;
    for (auto e : path)
        cout << e;
    cout << endl;

}

