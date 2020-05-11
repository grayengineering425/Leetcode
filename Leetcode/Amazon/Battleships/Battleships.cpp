#include "Battleships.h"

#include <sstream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace Amazon;

Battleships::Battleships() = default;

std::string Battleships::getResult(std::string& S, std::string& T)
{
	std::set<std::string> hits;

	std::stringstream st(T);
	std::string hit;

	while (std::getline(st, hit, ' ')) hits.insert(hit);
	
	std::stringstream	ss(S);
	std::string			coordinates;
	
	int numSinks = 0;
	int numHits  = 0;

	while (std::getline(ss, coordinates, ','))
	{
		std::set<std::string> ship;
		
		std::string topLeft			= "";
		std::string bottomRight		= "";
		
		topLeft		+= coordinates[0];
		topLeft		+= coordinates[1];
		bottomRight += coordinates[3];
		bottomRight += coordinates[4];
		
		for (char c = topLeft[0]; c <= bottomRight[0]; ++c)
		for (char d = topLeft[1]; d <= bottomRight[1]; ++d)
		{
			std::string cur = "";
		
			cur += c;
			cur += d;
		
			ship.insert(cur);
		}

		std::set<std::string> missing;
		std::set_difference(ship.begin(), ship.end(), hits.begin(), hits.end(), std::inserter(missing, missing.begin()));
		
		int difference = ship.size() - missing.size();
		
		if (difference	== ship.size()	) ++numSinks; else
		if (difference	 > 0			) ++numHits;
	}

	std::string ans = "";

	ans += std::to_string(numSinks);
	ans += ",";
	ans += std::to_string(numHits );
	
	return ans;
}
