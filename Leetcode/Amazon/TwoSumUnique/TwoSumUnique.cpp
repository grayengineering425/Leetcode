#include "TwoSumUnique.h"

#include <unordered_map>
#include <map>
#include <algorithm>

using namespace Amazon;

TwoSumUnique::TwoSumUnique() = default;

int TwoSumUnique::getUniquePairs(std::vector<int>& nums, int k)
{
	int ans = 0;

	std::unordered_map<int, int>		count;
	std::map<std::vector<int>, bool>	seen;

	for (const auto& num: nums) count[num]++;

	std::sort(nums.begin(), nums.end());

	for (size_t i=0; i<nums.size(); ++i)
	{
		int dif = std::abs(k - nums[i]);

		if (count.find(dif) != count.end())
		{
			std::vector<int> tmp = { std::min(nums[i], dif), std::max(nums[i], dif) };

			if (seen.find(tmp) == seen.end() && count[dif] == nums[i] && count[i] > 1)	ans++; else
			if (seen.find(tmp) == seen.end() && count[dif] != nums[i])					ans++;
			

			seen[tmp] = true;
		}

		while (i < nums.size() - 1 && nums[i+1] == nums[i]) ++i;

	}

	return ans;
}
