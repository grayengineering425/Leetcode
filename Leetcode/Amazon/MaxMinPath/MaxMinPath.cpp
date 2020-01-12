#include "MaxMinPath.h"

#include <queue>
#include <iostream>

using namespace Amazon;

MaxMinPath::MaxMinPath(std::vector<std::vector<int>>& grid)
	:	grid(grid)
{
}

int MaxMinPath::maximumMinimumPath()
{
	auto compare = [this](const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		return lhs[2] < rhs[2];
	};

	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> q(compare);

	std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

	std::vector<std::vector<std::pair<int, int>>> parent(grid.size(), std::vector<std::pair<int, int>>(grid[0].size(), {0, 0}));

	std::vector<std::vector<int>> moves = 
	{
			{ 1,  0}
		,	{-1,  0}
		,	{ 0,  1}
		,	{ 0, -1}
	};

	q.push( { 0, 0, grid[0][0] } );

	int min = INT_MAX;

	while (!q.empty())
	{
		auto cur = q.top();
		q.pop();

		int i	= cur[0];
		int j	= cur[1];
		int val = cur[2];

		visited[i][j] = true;

		min = std::min(min, val);

		if (i == grid.size() - 1 && j == grid[0].size()-1)
		{
			auto backTrack = parent[i][j];

			while (backTrack.first != 0 || backTrack.second != 0)
			{
				std::cout << backTrack.first << ", " << backTrack.second << ", " << grid[backTrack.first][backTrack.second] << " <- ";

				backTrack = parent[backTrack.first][backTrack.second];
			}

			std::cout << backTrack.first << ", " << backTrack.second << ", " << grid[backTrack.first][backTrack.second] << "\n";

			return min;
		}

		for (const auto& move: moves)
		{
			int newI = i + move[0];
			int newJ = j + move[1];

			if (newI < (int)grid.size() && newI > -1 && newJ < (int)grid[newI].size() && newJ > -1 && !visited[newI][newJ])
			{
				q.push({newI, newJ, grid[newI][newJ]});
				parent[newI][newJ] = std::make_pair(i, j);
			}
		}
	}
	return -1;
}
