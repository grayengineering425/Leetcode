#include "Amazon/Zombies/Zombies.h"
#include "Amazon/SearchSuggestion/Suggestion.h"
#include "Amazon/Cities/Cities.h"
#include "Amazon/TwoSum/TwoSum.h"
#include "Amazon/MaxAverageSubtree/MaxAverageSubtree.h"
#include "Amazon/RepairEdges/RepairEdges.h"
#include "Amazon/Spiral/Spiral.h"

#include <iostream>
#include <string>

using namespace Amazon;

int main()
{
	Spiral s(10);

	int maxSize = 4;

	auto spiral = s.generateMatrix();

	for (int i=0; i<spiral	 .size(); ++i){
	for (int j=0; j<spiral[i].size(); ++j)
	{
		std::string val = std::to_string(spiral[i][j]);

		std::cout << val;

		for (int k=val.size(); k<maxSize; ++k) std::cout << " ";
	} std::cout << "\n"; }
	
	return 0;
}