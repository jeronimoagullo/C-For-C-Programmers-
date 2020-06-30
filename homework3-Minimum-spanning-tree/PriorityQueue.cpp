#include "PriorityQueue.h"

void PriorityQueue::chgPrioirity(const QueueNode& queueElement)
{
	int node = queueElement.node;

	for (int i = 0; i < size(); i++) {
		if (queue[i].node == node) {

			if (queue[i].priority < queueElement.priority)
			{
				queue[i].priority = queueElement.priority;
				downwards(i);
			}
			else if (queue[i].priority > queueElement.priority)
			{
				queue[i].priority = queueElement.priority;
				upwards(i);
			}
			return;
		}
	}
}

void PriorityQueue::minPriority()
{
	// Copy the last value of the queue to the begin
	queue[0].node = queue.back().node;
	queue[0].priority = queue.back().priority;
	// remove the last value of the queue
	queue.pop_back();
	downwards(0);
}

bool PriorityQueue::contains(QueueNode& queueElement)
{
	int node = queueElement.node;

	for (auto q : queue) {
		if (q.node == node) {
			queueElement.priority = q.priority;
			return true;
		}
	}
	return false;
}

void PriorityQueue::Insert(const QueueNode& queueElement)
{
	//insert to the last value
	queue.push_back(queueElement);
	upwards(size() - 1);
}

QueueNode PriorityQueue::top()
{
	return queue[0];
}

int PriorityQueue::size()
{
	return queue.size();
}

void PriorityQueue::print()
{
	cout << "The priority Queue: " << endl;
	for (auto q : queue) {
		cout << q << ", ";
	}
	cout << endl;
}

void PriorityQueue::swap(int i, int j)
{
	int auxNode = queue[i].node;
	queue[i].node = queue[j].node;
	queue[j].node = auxNode;
	int auxPrio = queue[i].priority;
	queue[i].priority = queue[j].priority;
	queue[j].priority = auxPrio;
}

void PriorityQueue::upwards(int i)
{
	if (i <= 0) return;

	int parent = (i - 1) / 2;

	if (queue[i].priority < queue[parent].priority) {
		swap(i, (i - 1) / 2);
		upwards(parent);
	}
}

void PriorityQueue::downwards(int i) 
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (right < size())
	{
		if (queue[i].priority <= queue[left].priority &&
			queue[i].priority <= queue[right].priority)
		{
			return;
		}

		int smaller = queue[left].priority < queue[right].priority ? left : right;

		swap(i, smaller);
		downwards(smaller);
	}
	else if (left < size())
	{
		if (queue[i].priority <= queue[left].priority)
		{
			return;
		}

		swap(i, left);
		downwards(left);
	}
}

ostream& operator<<(ostream& out, const QueueNode& q)
{
	out << "(" << q.node << "):" << q.priority;
	return out;
}
