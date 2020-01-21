#pragma once
#include <vector>

namespace Amazon
{

class MergeIntervals
{
public:
	MergeIntervals(std::vector<std::vector<int>>& intervals);

	std::vector<std::vector<int>> merge();

private:
	std::vector<std::vector<int>> intervals;
};


}