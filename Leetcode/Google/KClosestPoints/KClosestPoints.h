#pragma once
#include <vector>

namespace Google
{
//https://leetcode.com/problems/k-closest-points-to-origin/
class KClosestPoints
{
public:
	KClosestPoints();

	std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int K);
};

}
