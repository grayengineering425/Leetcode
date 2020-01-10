#include "TwoSum.h"

#include <algorithm>

using namespace Amazon;

TwoSum::TwoSum(std::vector<int>& n)
	:	nums(n)
{
	std::sort(nums.begin(), nums.end());
}

int TwoSum::findUniquePairs(int target)
{
	int count = 0;

	int l = 0;
	int r = nums.size() - 1;

	while (l < r)
	{
		int sum = nums[l] + nums[r];

		if (sum == target)
		{
			count++;

			int curL = nums[l];
			int curR = nums[r];

			while (l < r && nums[l] == curL) l++;
			while (l < r && nums[r] == curR) r--;
		}
		else if (sum > target)
		{
			r--;
		}
		else
		{
			l++;
		}
	}
	return count;
}
