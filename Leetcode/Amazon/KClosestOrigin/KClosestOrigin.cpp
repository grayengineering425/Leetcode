#include "KClosestOrigin.h"

#include <queue>

using namespace Amazon;

KClosestOrigin::KClosestOrigin(std::vector<std::vector<int>>& points)
	:	points(points)
{
}

std::vector<std::vector<int>> KClosestOrigin::KClosest(int k)
{
	auto compare = [this](const Point & p1, const Point & p2)
	{
		return p1.distance > p2.distance;
	};

	std::vector<std::vector<int>>										kPoints;
	std::priority_queue<Point, std::vector<Point>, decltype(compare)>	pq(compare);
	
	for (const auto &point: points)  pq.push(Point(point[0], point[1]));
	
	int i=0;
	
	while (i < k && !pq.empty())
	{
	    Point cur = pq.top();
	    pq.pop();
	    
	    std::vector<int> tmp;
	    tmp.push_back(cur.x);
	    tmp.push_back(cur.y);
	    kPoints.emplace_back(tmp);
	    
	    i++;
	}
	
	return kPoints;
}
