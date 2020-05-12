#include "MinMaxPath.h"

#include <algorithm>
#include <iostream>

using namespace Amazon;

MinMaxPath::MinMaxPath() = default;

int MinMaxPath::getMinPath(std::vector<std::vector<int>>& grid)
{
	if (grid.empty()) return 0;

	std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), 0));

	dp[0][0] = INT_MAX;

	for (int i = 1; i < grid	.size(); ++i) { dp[i][0] = std::min(dp[i-1][0  ], grid[i][0]);  };
	for (int i = 1; i < grid[0]	.size(); ++i) { dp[0][i] = std::min(dp[0  ][i-1], grid[0][i]); };

	for (int i=1; i<grid	.size(); ++i)
	for (int j=1; j<grid[i]	.size(); ++j)
	{
		if (i == grid.size() - 1 && j == grid[i].size() - 1)	dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		else													dp[i][j] = std::max(std::min(dp[i - 1][j], grid[i][j]), std::min(dp[i][j - 1], grid[i][j]));
	}

	std::cout << dp[dp.size() - 1][dp[0].size() - 1] << std::endl;

	return dp[dp.size()-1][dp[0].size()-1];
}
