#pragma once
#include "DataStructures/Graph/Graph.h"

namespace Amazon
{

using namespace DataStructures;

class RepairEdges
{
public:
	RepairEdges(std::vector<std::vector<int>>& connections, std::vector<std::vector<int>>& repairs, int n);

	int minCostToRepair();

private:
	Graph		graph;
	UnionFind	unionFind;
};

}