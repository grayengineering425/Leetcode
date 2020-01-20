#include "NumberClusters.h"

#include <queue>
#include <tuple>

using namespace Amazon;

NumberClusters::NumberClusters(std::vector<std::vector<char>>& grid)
	:	grid(grid)
{
}

int NumberClusters::getNumber()
{
    if (grid.empty()) return 0;
    
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    
    int count = 0;
    
    for (int i=0; i<(int)grid	.size(); ++i)
    for (int j=0; j<(int)grid[i].size(); ++j)
    {
        if (visited[i][j]) continue;
        
        if (grid[i][j] == '1')
        {
            dfs(grid, visited, i, j);
            count++;
        }
        
        visited[i][j] = true;
    }
    return count;
}

void NumberClusters::dfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int i, int j)
{
    if (grid[i][j] == '0') return;
    
    visited[i][j] = true;
    
    if (i > 0							&& !visited[i - 1][j]) dfs(grid, visited, i - 1 , j     );
    if (i < (int)grid.size() - 1		&& !visited[i + 1][j]) dfs(grid, visited, i + 1 , j     );
    if (j > 0							&& !visited[i][j - 1]) dfs(grid, visited, i     , j - 1 );
    if (j < (int)grid[i].size() - 1		&& !visited[i][j + 1]) dfs(grid, visited, i     , j + 1 );
}
