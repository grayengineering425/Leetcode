#include "KClosestPoints.h"

#include <queue>

using namespace Google;

KClosestPoints::KClosestPoints() = default;

std::vector<std::vector<int>> KClosestPoints::kClosest(std::vector<std::vector<int>>& points, int K)
{
	if (K < 1 || points.empty()) return {};
	
	auto compare = [](const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
	    double distanceLeft  = std::sqrt(std::pow((double)lhs[0] - 0.0, 2) + std::pow((double)lhs[1] - 0, 2));
	    double distanceRight = std::sqrt(std::pow((double)rhs[0] - 0.0, 2) + std::pow((double)rhs[1] - 0, 2));
	    
	    return distanceLeft > distanceRight;
	};
	
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> pq(compare);
	
	for (const auto& point: points) pq.push(point);
	
	std::vector<std::vector<int>> ans;
	
	while (!pq.empty() && K > 0)
	{
	    ans.push_back(pq.top());
	    
	    pq.pop();
	    
	    --K;
	}
	
	return ans;
}
