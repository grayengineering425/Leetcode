#include "CourseScheduleII.h"

using namespace General;

CourseScheduleII::CourseScheduleII() = default;

std::vector<int> CourseScheduleII::findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
	std::vector<std::vector<int>> adj(numCourses, std::vector<int>(numCourses, 0));

    for (const auto& pre: prerequisites) adj[pre[0]][pre[1]] = 1;
        
    std::vector<bool>   visited (numCourses, false);
    std::vector<bool>   finished(numCourses, false);
    
    std::queue<int>     sorted;
    
    for (int u=0; u<numCourses; ++u) { if (!visited[u] && !topSort(adj, visited, finished, sorted, u)) return {}; }
    
    std::vector<int> ans;
    
    while(!sorted.empty()){ ans.push_back(sorted.front()); sorted.pop(); }
    
    return ans;
}

bool CourseScheduleII::topSort(std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& finished, std::queue<int>& sorted, int u)
{
	//if we reach a node who has already been visited, and not yet finished sorting its dependencies, then we have a cycle and no
    //topological sorting order exists
	if (visited[u]) return finished[u];
    
	visited[u] = true;
	
	for (int v=0; v<(int)adj[u].size(); ++v){ if (adj[u][v] && !topSort(adj, visited, finished, sorted, v)) return false; }

	finished[u] = true;
    
    sorted.push(u);
	
	return true;
}
