#include "CheapestFlights.h"

using namespace General;

CheapestFlights::CheapestFlights()
{
}

#include <iostream>

int CheapestFlights::findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K)
{
	std::vector<std::vector<int>> distanceTimes(n, { INT_MAX, 0 });
	
	distanceTimes[src] = { 0, 0 };
	
	int cycles = flights.size() - 1;
	
	for (int i=0; i<=K;				++i)
	for (int j=0; j<flights.size(); ++j)
	{
	    int u = flights[j][0];
	    int v = flights[j][1];
	    int d = flights[j][2];
	    
	    if (distanceTimes[u][0] != INT_MAX && distanceTimes[v][0] > distanceTimes[u][0] + d) distanceTimes[v] = { distanceTimes[u][0] + d, distanceTimes[u][1] + 1 };
	}
	
	return distanceTimes[dst][0] == INT_MAX ? -1 : distanceTimes[dst][0];
}
