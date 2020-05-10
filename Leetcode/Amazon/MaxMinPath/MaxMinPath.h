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
	std::vector<std::vector<int>> grid;
};

}