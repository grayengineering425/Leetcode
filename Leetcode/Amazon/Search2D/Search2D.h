#pragma once
#include <vector>

namespace Amazon
{

class Search2D
{
public:
	explicit Search2D(std::vector<std::vector<int>>& matrix);

	bool searchMatrix(int target);

private:
	std::vector<std::vector<int>> matrix;
};

}