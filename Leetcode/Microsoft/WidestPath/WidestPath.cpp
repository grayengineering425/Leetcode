#include "WidestPath.h"

#include <algorithm>

using namespace Microsoft;

WidestPath::WidestPath() = default;

int WidestPath::getWidest(std::vector<int>& x, std::vector<int>& y)
{
	if (x.empty()) return 0;

	std::sort(x.begin(), x.end());

	int widest = 0;

	for (size_t i=0; i<x.size()-1; ++i) widest = std::max(widest, x[i+1] - x[i]);

	return widest;
}
