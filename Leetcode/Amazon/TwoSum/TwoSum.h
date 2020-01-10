#pragma once
#include <vector>

namespace Amazon
{

class TwoSum
{
public:
	TwoSum(std::vector<int>& nums);

	int findUniquePairs(int target);

private:
	std::vector<int> nums;
};

}