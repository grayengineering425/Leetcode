#include "PartyChairs.h"

#include <algorithm>
#include <queue>

using namespace Leetcode;
using namespace Google;

PartyChairs::PartyChairs(std::vector<int>& guestEntry, std::vector<int>& guestExit)
	:	guestEntry	(guestEntry	)
	,	guestExit	(guestExit	)
{
}

int PartyChairs::minChairs()
{
	if (guestEntry.empty() || guestExit.empty()) return 0;

	int count = 0;

	auto compare = [](const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		return lhs[0] < rhs[0];
	};

	std::vector<std::vector<int>> guestIndex;

	for (int i=0; i<guestEntry.size(); ++i) guestIndex.push_back({ guestEntry[i], i });

	std::sort(guestEntry.begin(), guestEntry.end());

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	for (int i=0; i<guestIndex.size(); ++i)
	{
		auto guest = guestIndex[i];

		int guestEntryTime	= guest[0];
		int guestIndex		= guest[1];

		if (pq.empty()) count++;

		else
		{
			int firstToLeave = pq.top();

			if (firstToLeave <= guestEntryTime) pq.pop();

			else count++;
		}

		pq.push(guestExit[guestIndex]);
	}

	return count;
}
