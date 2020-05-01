#pragma once
#include <vector>

namespace General
{

class SprialMatrix
{
public:
	SprialMatrix();

	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
};

}
