#pragma once
#include <vector>

namespace Amazon
{

class TreasureIsland
{
public:
	TreasureIsland(std::vector<std::vector<char>>& map);

	int minSteps();
	int minSteps2();

private:
	std::vector<std::vector<char>> map;

};


}