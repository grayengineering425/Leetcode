#pragma once
#include <vector>
#include <memory>

#include "DataStructures/Graph/Graph.h"

namespace Amazon
{

using namespace DataStructures;

class Cities
{
public:
	Cities(std::vector<std::vector<int>>& connections, int n);

	int minimumCost();

private:

private:
	Graph		graph;
	UnionFind	unionFind;
};

}