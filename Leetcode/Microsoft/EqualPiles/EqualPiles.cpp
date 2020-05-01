#include "EqualPiles.h"

#include <unordered_map>
#include <algorithm>

using namespace Microsoft;

EqualPiles::EqualPiles() = default;

int EqualPiles::minMoves(std::vector<int>& piles)
{
	if (piles.size() < 2) return 0;

	std::sort(piles.begin(), piles.end(), std::greater<int>());

	int moves	= 0;

	int last	= piles[piles.size()-1];
	int i		= piles.size()-2;
	
	while (i > -1 && last == piles[i]) --i;

	if (i == -1) return moves;

	last = piles[i];

	int count = 0;
	int mult  = 1;

	while (i > -1)
	{
		++count;
		if (i == 0 || piles[i-1] != last)
		{
			moves += count * mult;

			count = 0;
			mult++;
			if (i != 0) last = piles[i-1];
		}

		--i;
	}

	return moves;
}
