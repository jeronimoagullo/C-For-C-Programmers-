#include "ShortestPath.h"

std::vector<int> ShortestPath::path(Graph& graph, int iniVertex, int endVertex)
{
	vector<int> route;

	if (iniVertex < 0 || iniVertex > graph.V()) return route;
	if (endVertex < 0 || endVertex > graph.V()) return route;


	if (dijkstra(graph, iniVertex, endVertex) == INFINITY)
	{
		return route;
	}

	int cur = endVertex;
	do
	{
		route.push_back(cur);
		cur = traces[cur];

	} while (cur != -1);

	reverse(route.begin(), route.end());

	return route;

    return std::vector<int>();
}

int ShortestPath::pathSize(Graph& graph, int iniVertex, int endVertex)
{
	return dijkstra(graph, iniVertex, endVertex);
}

int ShortestPath::dijkstra(Graph &graph, int iniVertex, int endVertex){

	if (iniVertex < 0 || iniVertex > graph.V()) return 0;
	if (endVertex < 0 || endVertex > graph.V()) return 0;

    int size = graph.V();
    PriorityQueue q;

	// initiate traces;
	traces.clear();
	traces.resize(size, -1);

    for (int i = 0; i < size; i++) {
        q.Insert(QueueNode(i, INF));
    }

    q.chgPrioirity(QueueNode(iniVertex, 0));

    while (q.size() > 0) {

        QueueNode top = q.top();
		q.minPriority();
        
        if (top.priority == INF) return INF;
        if (top.node == endVertex) return top.priority;

		// relax path
		vector<int> neighbors = graph.neighbors(top.node);

		QueueNode queueNode;
		for (int i = 0; i < neighbors.size(); i++)
		{
			queueNode.node = neighbors[i];
			if (q.contains(queueNode))
			{
				int edge = graph.get_edge_value(top.node, queueNode.node);
				if (edge + top.priority < queueNode.priority)
				{
					traces[queueNode.node] = top.node;
					queueNode.priority = edge + top.priority;
					q.chgPrioirity(queueNode);
				}
			}
		}
    }

    return INF;
}
