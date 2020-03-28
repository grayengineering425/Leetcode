#pragma once
#include <vector>
#include <queue>

namespace General
{
//https://leetcode.com/problems/cheapest-flights-within-k-stops
class CheapestFlights
{
public:
	CheapestFlights();

	int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K);
};

}
