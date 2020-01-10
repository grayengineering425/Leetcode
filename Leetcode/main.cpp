#include "Amazon/Zombies/Zombies.h"
#include "Amazon/SearchSuggestion/Suggestion.h"
#include "Amazon/Cities/Cities.h"
#include "Amazon/TwoSum/TwoSum.h"
#include "Amazon/MaxAverageSubtree/MaxAverageSubtree.h"
#include "Amazon/RepairEdges/RepairEdges.h"

#include <iostream>

using namespace Amazon;

int main()
{
	std::vector<std::vector<int>> connections	= { {1, 2}, {2, 3}, {4, 5}, {5, 6}, {1, 5}, {2, 4}, {3, 4} };
	std::vector<std::vector<int>> repairs		= { {1, 5, 110}, {2, 4, 84}, {3, 4, 79} };

	RepairEdges r(connections, repairs, 6);

	std::cout << r.minCostToRepair() << std::endl;

	return 0;
}