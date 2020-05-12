#pragma once
#include <vector>

namespace Amazon
{

//https://leetcode.com/discuss/interview-question/383669/
class MinMaxPath
{
public:
	MinMaxPath();

	int getMinPath(std::vector<std::vector<int>>& grid);
};

}