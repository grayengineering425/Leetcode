#include "KEmptySlots.h"

#include <map>

using namespace General;

KEmptySlots::KEmptySlots() = default;

int KEmptySlots::kEmptySlots(std::vector<int>& bulbs, int K)
{
	std::map<int, bool> turnedOn;
	
	for (int i=0; i<bulbs.size(); ++i)
	{
	    turnedOn[bulbs[i]] = true;
	    
	    auto cur = turnedOn.find(bulbs[i]);
	    
	    bool searching = cur != turnedOn.begin();
	    
	    while (searching)
	    {
	        cur--;
	        
	        int inBetween = bulbs[i] - cur->first - 1;
	        
	        if (inBetween == K)                                             return i+1;           else
	        if (cur == turnedOn.begin() || inBetween > K|| inBetween < K)   searching = false;
	    }

		
		cur = turnedOn.find(bulbs[i]);

		searching = std::next(cur) != turnedOn.end();

		while (searching)
		{
			cur++;

			int inBetween = cur->first - bulbs[i] - 1;

			if (inBetween == K)														return i + 1;           else
			if (std::next(cur) != turnedOn.end() || inBetween > K || inBetween < K)	searching = false;
		}
	}
	return -1;
}
