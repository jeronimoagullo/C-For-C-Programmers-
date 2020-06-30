#include "PrimMST.h"


int PrimMST::calculateMST() {
	vector<int> prevs(graph->V(), -1);
	PriorityQueue q = PriorityQueue();
	
	// initialize the priority queue
	for (int i = 0; i < graph->V(); i++) {
		q.Insert(QueueNode(i, INF));
	}

	QueueNode qNode(0, 0);
	q.chgPrioirity(qNode);

	int totalCost = 0;
	while (q.size() > 0)
	{
		QueueNode top = q.top();
		q.minPriority();

		int curVertice = top.node;
		int curCost = top.priority;

		if (prevs[curVertice] != -1)
		{
			totalCost += curCost;
			path.push_back(Edge(prevs[curVertice], curVertice));
		}

		// neighbors edges search
		vector<int> neighbors = graph->neighbors(curVertice);
		for (int i = 0; i < neighbors.size(); i++)
		{
			int v = neighbors[i];
			qNode.node = v;
			if (q.contains(qNode))
			{
				int cost = graph->get_edge_value(curVertice, v);
				if (qNode.priority > cost)
				{
					qNode.priority = cost;
					q.chgPrioirity(qNode);
					prevs[v] = curVertice; // update previous vertices
				}
			}
		}
	}

	return totalCost;
}

vector<Edge> PrimMST::getPathMST()
{
	return path;
}
