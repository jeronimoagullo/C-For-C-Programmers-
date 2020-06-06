/****************************************************************************************************/
/*                                      											                */
/* Author:	Jerónimo Agulló															                */
/* Date:	06/06/2020															                    */
/* Brief:	This file contains the main function for testing the Graph, PriorityQueue and           */
/*          ShortestPath classes for the homework 2 of the C++ for C programmers course.            */
/*                                      											                */
/*			TestGraph: tests the functionality of the Graph class and its representation	    	*/
/*			TestQueue: tests the functionality of the Priority queue								*/
/*			testRandomGraph: tests the fgeneration of a random graph with a given density			*/
/*			testShortestPath: tests the ShortestPath method, using a given example                  */
/*                  The example can be found here https://www.youtube.com/watch?v=LLx0QVMZVkk		*/
/*                                      											                */
/****************************************************************************************************/

#include<iostream>
#include "Graph.h"
#include "PriorityQueue.h"
#include "ShortestPath.h"


void testQueue();
void testGraph();
void testRandomGraph();
void testShortestPath();

int main()
{
   
    testGraph();
    testRandomGraph();
    testQueue();
    testShortestPath();
 
    return 0;
}

// This function tests the functionality of the Priority queue
void testQueue() {
    cout << endl << "########################################################" << endl;
    cout << "################## starting testQueue ##################" << endl;

    PriorityQueue q;
    srand(time(0));
    const int MAX_ELEMENTS = 13;

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        QueueNode element = QueueNode(i, rand() % 20);
        q.Insert(element);
        cout << element << ", ";
    }

    cout << endl;
    cout << "******************************" << endl;
    cout << "Top element: " << q.top() << endl;
    cout << "******************************" << endl;
    q.print();

    cout << "******************************" << endl;
    cout << "removed the top element: " << endl;
    q.minPriority();
    q.print();

    cout << "******************************" << endl;
    cout << "change the priority of node 5 to 0: " << endl;
    q.chgPrioirity(QueueNode(5, 0));
    q.print();

    cout << "******************************" << endl;
    QueueNode queueNode2 = QueueNode(2, 10);
    QueueNode queueNode8 = QueueNode(8, 10);
    cout << "Does the queue contain the queue element 2?: " << q.contains(queueNode2) << endl;
    cout << "Does the queue contain the queue element 8?: " << q.contains(queueNode8) << endl;

    cout << "################## end of testQueue ##################" << endl;
    cout << "########################################################" << endl;

}


// This function tests the functionality of the Graph class and its representation
void testGraph() {
    cout << endl << "########################################################" << endl;
    cout << "################## starting testGraph ##################" << endl;

    Graph graph = Graph(5, 0, 0, 100);

    graph.add(0, 1, 10);
    graph.add(0, 2, 5);
    graph.add(0, 3, 2);
    graph.add(2, 4, 15);
    graph.add(2, 3, 1);
    graph.add(3, 4, 8);
    cout << "number of edges: " << graph.E() << endl;
    graph.print();

    graph.remove(2, 3);
    cout << "removed the edge 2,3" << endl;
    cout << "number of edges: " << graph.E() << endl;
    graph.print();

    cout << "set edge 0,2 to value 3.45" << endl;
    graph.set_edge_value(0, 2, 3.45);

    cout << "does the edge 0,2 exist? " << graph.adjacent(0, 2) << endl;
    cout << "does the edge 0,4 exist? " << graph.adjacent(0, 4) << endl;
    cout << "does the edge 1,3 exist? " << graph.adjacent(2, 3) << endl;
    graph.print();

    vector <int> neighbors0 = graph.neighbors(0);
    cout << "neighbors of 0" << ": ";
    for (auto i : neighbors0) {
        cout << i << ", ";
    }
    cout << endl;
    vector <int> neighbors4 = graph.neighbors(4);
    cout << "neighbors of 4" << ": ";
    for (auto i : neighbors4) {
        cout << i << ", ";
    }
    cout << endl;
    cout << "The weight value of edge (0,2) is: " << graph.get_edge_value(0, 2) << endl;

    cout << "################## end of testGraph ##################" << endl;
    cout << "########################################################" << endl;

}

// This function tests the fgeneration of a random graph with a given density
void testRandomGraph() {
    cout << endl << "##############################################################" << endl;
    cout << "################## starting testRandomGraph ##################" << endl;

   Graph graph = Graph(10,25,10,25);
   cout << "number of edges (10 nodes and 25% of density): " << graph.E() << endl;

   graph.print();
   cout << "################## end of testRandomGraph ##################" << endl;
   cout << "############################################################" << endl;
}

// This functionality test the ShortestPath method, using a given example
// The example can be found here https://www.youtube.com/watch?v=LLx0QVMZVkk
void testShortestPath() {
    cout << endl << "##############################################################" << endl;
    cout << "################## starting testShortestPath ##################" << endl;

    Graph graph = Graph(8, 0, 0, 10);

    graph.add(0, 2, 1);
    graph.add(0, 1, 3);
    graph.add(1, 6, 5);
    graph.add(1, 3, 1);
    graph.add(2, 3, 2);
    graph.add(2, 5, 5);
    graph.add(3, 5, 2);
    graph.add(3, 4, 4);
    graph.add(4, 7, 1);
    graph.add(4, 6, 2);
    graph.add(5, 7, 3);

    cout << "number of edges: " << graph.E() << endl;
    graph.print();

    ShortestPath path = ShortestPath();
    cout << "the shortest distant from (0) to (8) is: " << path.pathSize(graph, 0, 7) << endl;

    vector<int> route = path.path(graph, 0, 7);
    cout << "Route: ";
    for (auto node : route) {
        cout << node << " -> ";
    }
    cout << "end" << endl;

    cout << "################## end of testShortestPath ##################" << endl;
    cout << "############################################################" << endl;
}