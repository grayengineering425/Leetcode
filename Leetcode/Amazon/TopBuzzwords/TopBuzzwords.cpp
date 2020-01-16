#include "TopBuzzwords.h"

#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cctype>

using namespace Amazon;

TopBuzzwords::TopBuzzwords(std::vector<std::string>& toys, std::vector<std::string>& quotes)
	:	toys	(toys)
	,	quotes	(quotes)
{
}

std::vector<std::string> TopBuzzwords::topN(int n)
{
	std::unordered_map<std::string, int> counts;
	std::unordered_map<std::string, int> countQuotes;

	std::unordered_map<char, bool> delimeters;
	delimeters['[' ] = true;
	delimeters['\\'] = true;
	delimeters['!' ] = true;
	delimeters['?' ] = true;
	delimeters[',' ] = true;
	delimeters[';' ] = true;
	delimeters['.' ] = true;
	delimeters[']' ] = true;
	delimeters[' ' ] = true;

	for (const auto& quote: quotes)
	{
		std::string curWord;
		std::unordered_map<std::string, bool> seen;

		for (size_t i=0; i<quote.size(); ++i)
		{
			char c = quote[i];

			if (delimeters[c])
			{
				counts[curWord]++;
				
				if (!seen[curWord]) countQuotes[curWord]++;

				seen[curWord] = true;

				curWord = "";

				while (i < quote.size() && delimeters[quote[i]]) i++;
				i--;
			}
			else
			{
				curWord += std::tolower(c);
			}
		}

		if (!curWord.empty())
		{
			counts[curWord]++;
			if (!seen[curWord]) countQuotes[curWord]++;
		}
	}

	auto compare = [this](const std::tuple<std::string, int, int>& lhs, const std::tuple<std::string, int, int>& rhs)
	{
		int countTotalL = std::get<1>(lhs);
		int countTotalR = std::get<1>(rhs);

		int countQuoteL = std::get<2>(lhs);
		int countQuoteR = std::get<2>(rhs);

		return countTotalL != countTotalR ? countTotalL < countTotalR : countQuoteL < countQuoteR;
	};

	std::priority_queue<std::tuple<std::string, int, int>, std::vector<std::tuple<std::string, int, int>>, decltype(compare)> q(compare);

	for (const auto& count: counts)
	{
		if (std::find(toys.begin(), toys.end(), count.first) != toys.end()) q.push(std::make_tuple(count.first, count.second, countQuotes[count.first]));
	}

	std::vector<std::string> ans;

	while (!q.empty() && n > 0)
	{
		auto cur = q.top();
		q.pop();

		ans.push_back(std::get<0>(cur));

		n--;
	}

	return ans;
}
