#include "PairWithSum.h"

#include <unordered_map>
#include <algorithm>

using namespace Amazon;

PairWithSum::PairWithSum(std::vector<int>& nums)
	:	nums(nums)
{
}

std::vector<int> PairWithSum::findPair(int target)
{
	target -= 30;

	std::vector<int> ans;

	std::unordered_map<int, int> seen;

	for (size_t i=0; i<nums.size(); ++i)
	{
		int partner = target - nums[i];

		if (seen.find(partner) != seen.end())
		{
			if (ans.empty()){ ans.push_back(seen[partner]); ans.push_back(i); }
			else
			{
				int curMax = std::max(nums[i],		partner		);
				int preMax = std::max(nums[ans[0]], nums[ans[1]]);

				if (curMax > preMax)
				{
					ans[0] = seen[partner];
					ans[1] = i;
				}
			}
		}
		seen[nums[i]] = i;
	}
	return ans;
}
