#include "PointOfLattice.h"

#include <sstream>

using namespace Amazon;

PointOfLattice::PointOfLattice() = default;

std::string PointOfLattice::getPoint(int ax, int ay, int bx, int by)
{
	int dx = bx - ax;
	int dy = by - ay;

	//rotate 90 degrees;
	int tmp = dx;
	
	dx = dy;
	dy = -tmp;

	//reduce vector length to minimum value
	int r = std::abs(gcd(dx, dy));

	dx /= r;
	dy /= r;

	//since we start from B, add the points to find new co-ordinates
	dx = bx + dx;
	dy = by + dy;

	std::stringstream ss;

	ss << dx << "," << dy;

	return ss.str();
}

int PointOfLattice::gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
