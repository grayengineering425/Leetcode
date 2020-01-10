#include "RepairEdges.h"

#include <algorithm>
#include <map>

using namespace Amazon;
using namespace DataStructures;

RepairEdges::RepairEdges(std::vector<std::vector<int>>& connections, std::vector<std::vector<int>>& repairs, int n)
	:	graph	 (n, connections.size() + repairs.size())
	,	unionFind(n)
{
	std::map<std::vector<int>, bool> seen;

	for (const auto& connection: repairs)
	{
		graph.edges.push_back((std::make_shared<Edge>(connection[0] - 1, connection[1] - 1, connection[2])));

		seen[{connection[0] - 1, connection[1] - 1}] = true;
	}

	for (const auto& connection : connections)
	{
		if (!seen[{connection[0]-1, connection[1]-1}]) graph.edges.push_back((std::make_shared<Edge>(connection[0] - 1, connection[1] - 1, 0)));
	}


	std::sort(graph.edges.begin(), graph.edges.end(), [this](const std::shared_ptr<Edge>& lhs, const std::shared_ptr<Edge>& rhs)
	{
		return lhs->weight < rhs->weight;
	});
}

int RepairEdges::minCostToRepair()
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
