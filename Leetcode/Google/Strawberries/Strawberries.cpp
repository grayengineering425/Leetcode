#include "Strawberries.h"

#include <algorithm>

using namespace Leetcode;
using namespace Google;

Strawberries::Strawberries() = default;

int Strawberries::getMax(int max, std::vector<int>& bushes)
{
	std::vector<int> dp(bushes.size(), 0);

	dp[0] = bushes[0];
	dp[1] = bushes[1];


	for (int i=2; i<bushes.size(); ++i)
	{
		dp[i] = dp[i-1];

		for (int j=i-2; j>-1; --j)
		{
			if (bushes[i] + dp[j] <= max) dp[i] = std::max(dp[i], bushes[i] + dp[j]);
		}
	}

	return dp[dp.size()-1];
}
