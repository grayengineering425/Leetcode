#include "Amazon/Zombies/Zombies.h"
#include "Amazon/SearchSuggestion/Suggestion.h"
#include "Amazon/Cities/Cities.h"
#include "Amazon/TwoSum/TwoSum.h"
#include "Amazon/MaxAverageSubtree/MaxAverageSubtree.h"
#include "Amazon/RepairEdges/RepairEdges.h"
#include "Amazon/Spiral/Spiral.h"
#include "Amazon/LongestPalindrome/LongestPalindrome.h"
#include "Amazon/MaxMinPath/MaxMinPath.h"

#include <iostream>
#include <string>

using namespace Amazon;

int main()
{
	std::vector<std::vector<int>> grid = { {2,2,1,2,2,2},{1,2,2,2,1,2} };
	MaxMinPath m(grid);

	std::cout << m.maximumMinimumPath() << std::endl;

	return 0;
}