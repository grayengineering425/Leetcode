#pragma once
#include <vector>

namespace Amazon {
//https://leetcode.com/discuss/interview-question/372434
class TwoSumUnique {
public:
	TwoSumUnique();

	int getUniquePairs(std::vector<int>& nums, int k);
};

}