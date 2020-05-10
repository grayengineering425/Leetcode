#pragma once
#include <vector>

namespace Amazon
{

class MinCostRepairEdges
{
public:
	MinCostRepairEdges();

	int minCost(std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& edgesToRepair, int n);

private:
	int		find		(int u);
	bool	createsCycle(int u, int v);
	void	createUnion	(int u, int v);

private:
	std::vector<int> parents;
};

}