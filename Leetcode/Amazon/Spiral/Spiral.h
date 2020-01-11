#pragma once
#include <vector>

namespace Amazon
{

class Spiral
{
public:
	Spiral(int n);

	std::vector<std::vector<int>> generateMatrix();

private:
	int n;
};

}