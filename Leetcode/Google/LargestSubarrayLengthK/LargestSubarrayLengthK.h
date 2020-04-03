#pragma once
#include <vector>

namespace Google
{
//https://leetcode.com/discuss/interview-question/352459/
class LargestSubarrayLengthK
{
public:
	LargestSubarrayLengthK();

	std::vector<int> getLargest			(std::vector<int>& nums, int k);
	std::vector<int> getLargestByStart	(std::vector<int>& nums, int k);

private:
	bool getMaxArray(std::vector<int>& lhs, std::vector<int>& rhs);
};

}
