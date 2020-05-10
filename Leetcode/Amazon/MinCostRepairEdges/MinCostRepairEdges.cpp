#include "MinCostRepairEdges.h"

#include <queue>
#include <map>

using namespace Amazon;

MinCostRepairEdges::MinCostRepairEdges() = default;

int MinCostRepairEdges::minCost(std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& edgesToRepair, int n)
{
	parents = std::vector<int>(n+1, -1);

	auto compare = [](const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		return lhs[2] > rhs[2];
	};

	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> pq(compare);

	std::map<std::vector<int>, bool> seen;

	for (const auto& edge : edgesToRepair){									pq.push({ edge[0], edge[1], edge[2] }); seen[{ edge[0], edge[1] }] = true; }
	for (const auto& edge : edges		 ){ if (!seen[{edge[0], edge[1]}])	pq.push({ edge[0], edge[1], 0		}); }

	int cost	 = 0;
	int clusters = n;

	while (!pq.empty() && clusters > 1)
	{
		auto cur = pq.top();
		pq.pop();

		int u = cur[0];
		int v = cur[1];
		int c = cur[2];

		if (createsCycle(u, v)) continue;

		createUnion(u, v);

		cost += c;
		--clusters;
	}

	return clusters == 1 ? cost : -1;
}

int MinCostRepairEdges::find(int u)
{
	if (parents[u] == -1) return u;

	return find(parents[u]);
}

bool MinCostRepairEdges::createsCycle(int u, int v)
{
	int parentU = find(u);
	int parentV = find(v);

	return parentU == parentV;
}

void MinCostRepairEdges::createUnion(int u, int v)
{
	int parentU = find(u);
	int parentV = find(v);

	if (parentU != parentV) parents[parentU] = parentV;
}
