#pragma once
#include <vector>

namespace Amazon
{

class PrisonCells
{
public:
	PrisonCells();

	std::vector<int> prisonAfterNDays(std::vector<int>& cells, int N);
};

}