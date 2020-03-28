#include "CourseSchedule.h"

using namespace General;

CourseSchedule::CourseSchedule() = default;

bool CourseSchedule::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
	std::vector<std::vector<int>> adj(numCourses, std::vector<int>(numCourses, 0));

	for (const auto& pre: prerequisites) adj[pre[0]][pre[1]] = 1;
	    
	std::vector<bool> visited(numCourses,   false);
	std::vector<bool> finished(numCourses,  false);

	for (int u=0; u<numCourses; ++u) { if (!visited[u] && !topSort(adj, visited, finished, u)) return false; }

	return true;
}

bool CourseSchedule::topSort(std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& finished, int u)
{
	if (visited[u]) return finished[u];
        
	visited[u] = true;
	
	for (int v=0; v<(int)adj[u].size(); ++v){ if (adj[u][v] && !topSort(adj, visited, finished, v)) return false; }

	finished[u] = true;
	
	return true;
}
