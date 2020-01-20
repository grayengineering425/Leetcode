#pragma once
#include <vector>

namespace Amazon
{

class NumberClusters
{
public:
	NumberClusters(std::vector<std::vector<char>>& grid);

	int getNumber();

private:
	void dfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, int i, int j);

private:
	std::vector<std::vector<char>> grid;
};

}