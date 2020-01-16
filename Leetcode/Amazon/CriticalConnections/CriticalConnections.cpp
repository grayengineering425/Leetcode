#include "CriticalConnections.h"

#include <algorithm>

using namespace Amazon;

CriticalConnections::CriticalConnections(std::vector<std::vector<int>>& connections, int n)
	:	n(n)
{
	std::vector<std::vector<int>> adj(n, std::vector<int>());

	for (const auto& edge : connections) { adj[edge[0]].push_back(edge[1]); adj[edge[1]].push_back(edge[0]); }
}

std::vector<std::vector<int>> CriticalConnections::run()
{
	int time = 0;

	std::vector<int> prt(n, -1);
	std::vector<int> dst(n, -1);
	std::vector<int> low(n, 0);

	for (int i = 0; i < n; ++i) if (dst[i] == -1) dfs(i, dst, low, time, prt);

	return ans;
}

void CriticalConnections::dfs(int u, std::vector<int>& dst, std::vector<int>& low, int & time, std::vector<int>& prt)
{
	dst[u] = low[u] = ++time;
        
    for (size_t i=0; i<adj[u].size(); ++i)
    {
        int v = adj[u][i];
        
        prt[v] = u;
        
        if (dst[v] == -1)
        {
            dfs(v, dst, low, time, prt);
            
            low[u] = std::min(low[u], low[v]);
            
            if (low[v] > dst[u]) ans.push_back({u, v});
        }
        else if(prt[u] != v)
        {
            low[u] = std::min(low[u], dst[v]);
        }
    }
}
