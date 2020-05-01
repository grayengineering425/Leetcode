#include "StoresAndHouses.h"

#include <algorithm>

using namespace Leetcode;
using namespace Google;

StoresAndHouses::StoresAndHouses() = default;

std::vector<int> StoresAndHouses::getClosestStores(std::vector<int>& houses, std::vector<int>& stores)
{
	std::sort(stores.begin(), stores.end());

	std::vector<int> closest(houses.size(), 0);

	for (int i=0; i<houses.size(); ++i)
	{
		closest[i] = binarySearch(stores, houses[i]);
	}

	return closest;
}

int StoresAndHouses::binarySearch(std::vector<int>& stores, int location)
{
	int l = 0;
	int r = stores.size()-1;

	while (l <= r)
	{
		int mid = (l + r) / 2;

		if (stores[mid] == location) return stores[mid]; else
		if (stores[mid]  > location) r = mid-1;
		else						 l = mid+1;
	}

	int lDist = l > -1 && l < stores.size() ? stores[l] : INT_MAX;
	int rDist = r > -1 && r < stores.size() ? stores[r] : INT_MAX;

	lDist = std::abs(location - lDist);
	rDist = std::abs(location - rDist);

	if (lDist == rDist) return stores[l] < stores[r] ? stores[l] : stores[r];
	else				return lDist < rDist		 ? stores[l] : stores[r];
}
