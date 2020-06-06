/****************************************************************************************************/
/*                                      											                */
/* Author:	Jerónimo Agulló															                */
/* Date:	06/06/2020															                    */
/* Brief:	This class is an implementation of a Priority Queue based on a min-heap                 */
/*                                      											                */
/****************************************************************************************************/
#pragma once

#include <list>
#include <vector>
#include <iostream>

using namespace std;
const int INF = INT_MAX;

class QueueNode
{
public:
	int node;
	int priority;

	QueueNode(int symbol = -1, int priority = INF) :
		node(symbol), priority(priority){}

	friend ostream& operator<<(ostream& out, const QueueNode& q);
};


class PriorityQueue
{

	
public:

	// changes the priority(node value) of queue element.
	void chgPrioirity(const QueueNode& queueElement);
	// removes the top element of the queue (the first one, the root)
	void minPriority();
	// does the queue contain queue_element.
	bool contains(QueueNode& queueElement);
	// insert queue_element into queue
	void Insert(const QueueNode& queueElement);
	// returns the top element of the queue.
	QueueNode top();
	// return the number of queue_elements.
	int size();
	// print the queue
	void print();

private:
	// The queue which holds all the values
	vector<QueueNode> queue;

	// Internals functions for swap and move a value downwards and upwards
	void swap(int i, int j);
	void downwards(int i);
	void upwards(int i);
};
