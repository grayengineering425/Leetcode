#include "LongestWithoutConsecutive.h"

#include <queue>

using namespace Amazon;

LongestWithoutConsecutive::LongestWithoutConsecutive() = default;

std::string LongestWithoutConsecutive::getLongest(int a, int b, int c)
{
	std::string ans = "";
	
	auto compare = [](const std::pair<char, int>& lhs, const std::pair<char, int>& rhs)
	{
		return lhs.second < rhs.second;
	};
	
	std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(compare)> pq(compare);

	if (a > 0) pq.push(std::make_pair('a', a));
	if (b > 0) pq.push(std::make_pair('b', b));
	if (c > 0) pq.push(std::make_pair('c', c));

	while (!pq.empty())
	{
		auto mostFreq	= pq.top();
		char mostC		= mostFreq.first;
		int  mostCount	= mostFreq.second;

		pq.pop();

		for (int i=0; i<2; ++i)
		{
			if (mostCount == 0) break;

			ans += mostC;
			mostCount--;
		}

		if (pq.empty()) break;

		auto nextFreq = pq.top();
		char nextC		= nextFreq.first;
		int  nextCount	= nextFreq.second;

		pq.pop();

		//if we have two more of our most frequent than our next, we know we will repeat this pattern, so we want to reserve as much cushioning as possible
		int cushion = mostFreq.second - 2 >= nextCount ? 1 : 2;

		for (int i = 0; i < cushion; ++i)
		{
			if (nextCount == 0) break;
			
			ans += nextC;
			nextCount--;
		}

		if (mostCount > 0) pq.push(std::make_pair(mostC, mostCount));
		if (nextCount > 0) pq.push(std::make_pair(nextC, nextCount));
	}

	return ans;
}
