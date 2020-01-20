#pragma once
#include <vector>

namespace Amazon
{

class PairWithSum
{
public:
	PairWithSum(std::vector<int>& nums);

	std::vector<int> findPair(int target);

private:
	std::vector<int> nums;
};

}