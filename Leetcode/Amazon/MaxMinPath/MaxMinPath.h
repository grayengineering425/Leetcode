#pragma once

#include "DataStructures/Graph/Graph.h"

namespace Amazon
{

using namespace DataStructures;

class MaxMinPath
{
public:
	MaxMinPath(std::vector<std::vector<int>>& grid);

	int maximumMinimumPath();

private:
	std::pair<int, int> getMaxDistance(std::vector<std::vector<int>>& dist, std::vector<std::vector<bool>>& visited);

private:
	std::vector<std::vector<int>> grid;
};

}