#include "GraphBST.h"

#include <queue>

using namespace General;

GraphBST::GraphBST() = default;

bool GraphBST::isGraphBST(std::vector<std::vector<int>>& edges, int n)
{
	parents = std::vector<int>(n, -1);

	std::vector<std::vector<int>> adj(n);

	for (const auto& edge: edges)
	{
		if (edge.size() != 2) continue;

		int u = edge[0]-1;
		int v = edge[1]-1;

		adj[u].push_back(v);

		//check if we have more than two children
		if (adj[u].size() > 2) return false;
	}

	std::queue<int>		q;
	std::vector<int>	visited(n, false);

	q.push(0);

	visited[0] = true;

	int clusters = n;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (const auto& v: adj[u])
		{
			if (!visited[v])
			{
				if (createsCycle(u, v)) return false;
				createUnion(u,v);

				visited[v] = true;
				q.push(v);

				--clusters;
			}
		}
	}

	return clusters == 1;
}

bool GraphBST::createsCycle(int u, int v)
{
	int parentU = find(u);
	int parentV = find(v);

	return parentU == parentV;
}

void GraphBST::createUnion(int u, int v)
{
	int parentU = find(u);
	int parentV = find(v);

	if (parentU != parentV) parents[v] = parentU;
}

int GraphBST::find(int u)
{
	if (parents[u] == -1) return u;

	return find(parents[u]);
}
