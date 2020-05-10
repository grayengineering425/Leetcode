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
	
	std::vector<std::vector<int>> moves = 
	{
	        { 1,  0}
	    ,	{ 0,  1}
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
	        return min;
	
	    for (const auto& move: moves)
	    {
	        int newI = i + move[0];
	        int newJ = j + move[1];
	
	        if (newI < grid.size() && newI > -1 && newJ < grid[newI].size() && newJ > -1 && !visited[newI][newJ])
	        {
	            q.push({newI, newJ, grid[newI][newJ]});
	        }
	    }
	}
	return -1;
}
