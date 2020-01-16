#pragma once
#include <vector>

namespace Amazon
{

struct Point
{
	Point(int X, int Y)
		:	x(X)
		,	y(Y)
	{
		distance = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
	}

	int x;
	int y;

	double distance;
};

class KClosestOrigin
{
public:
	KClosestOrigin(std::vector<std::vector<int>>& points);

	std::vector<std::vector<int>> KClosest(int k);

private:
	std::vector<std::vector<int>> points;
};

}
