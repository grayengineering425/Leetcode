#include "LargestSubarrayLengthK.h"

#include <deque>

using namespace Google;

LargestSubarrayLengthK::LargestSubarrayLengthK() = default;

std::vector<int> LargestSubarrayLengthK::getLargest(std::vector<int>& nums, int k)
{
	if (nums.size() < k) return {};

	std::vector<int> cur (k, 0);
	std::vector<int> max (k, 0);

	for (int i=0; i<k; ++i) cur[i] = nums[i];

	std::memcpy(max.data(), cur.data(), k * sizeof(int));

	for (int i=k; i<nums.size(); ++i)
	{
		cur.erase(cur.begin(), cur.begin()+1);

		cur.push_back(nums[i]);

		if (getMaxArray(cur, max)) std::memcpy(max.data(), cur.data(), k * sizeof(int));
	}

	return max;
}

std::vector<int> LargestSubarrayLengthK::getLargestByStart(std::vector<int>& nums, int k)
{
	if (nums.size() < k) return {};

	std::vector<int> max (k, 0);

	std::memcpy(max.data(), nums.data(), k * sizeof(int));
	
	int i=1;

	while (i < nums.size() - k + 1)
	{
		if (nums[i] > max[0]) std::memcpy(max.data(), nums.data() + i, k * sizeof(int));

		++i;
	}

	return max;
}

bool LargestSubarrayLengthK::getMaxArray(std::vector<int>& lhs, std::vector<int>& rhs)
{
	for (int i=0; i<lhs.size(); ++i)
	{
		if (lhs[i] == rhs[i])	continue;		else
		if (lhs[i]  > rhs[i])	return true;
		else					return false;
	}

	return true;
}
