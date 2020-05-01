#pragma once
#include <vector>

namespace Amazon
{

class PointOfLattice
{
public:
	PointOfLattice();

	std::string getPoint(int ax, int ay, int bx, int by);

private:
	int gcd(int x, int y);
};

}