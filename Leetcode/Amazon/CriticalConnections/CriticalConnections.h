#pragma once
#include <vector>

namespace Amazon
{

class CriticalConnections
{
public:
	CriticalConnections(std::vector<std::vector<int>>& connections, int n);

	std::vector<std::vector<int>> run();

private:
	void dfs(int u, std::vector<int>& dst, std::vector<int>& low, int& time, std::vector<int>& prt);

private:
	std::vector<std::vector<int>> adj;
	std::vector<std::vector<int>> ans;

	int n;
};

}