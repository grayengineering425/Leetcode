#include "Cities.h"

#include <algorithm>

using namespace Amazon;
using namespace DataStructures;

Cities::Cities(std::vector<std::vector<int>>& connections, int n)
	:	graph		(n, connections.size())
	,	unionFind	(n)
{
	for (const auto& connection: connections) graph.edges.push_back(std::make_shared<Edge>(connection[0]-1, connection[1]-1, connection[2]));

	std::sort(graph.edges.begin(), graph.edges.end(), [this](const std::shared_ptr<Edge>& lhs, const std::shared_ptr<Edge>& rhs)
	{
		return lhs->weight < rhs->weight;
	});
}

int Cities::minimumCost()
{
	int i			= 0;
	int clusters	= graph.v;
	int distance	= 0;

	while (i < graph.e && clusters > 1)
	{
		auto edge = graph.edges[i++];

		if (!edge) continue;

		if (unionFind.createsCycle(edge)) continue;

		unionFind.createUnion(edge->src, edge->dst);
		
		clusters--;
		distance += edge->weight;
	}

	return clusters == 1 ? distance : -1;
}
