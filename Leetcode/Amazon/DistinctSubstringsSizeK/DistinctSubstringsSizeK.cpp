#include "DistinctSubstringsSizeK.h"

#include <unordered_map>

using namespace Amazon;

DistinctSubstringsSizeK::DistinctSubstringsSizeK() = default;

std::vector<std::string> DistinctSubstringsSizeK::getSubstrings(const std::string & s, int k)
{
	if (s.size() < k || k <= 0) return {};

	std::vector<std::string>				ans;
	std::unordered_map<std::string, bool>	seen;
	std::unordered_map<char, int>			count;

	int l=0;
	int r=0;

	while (r < static_cast<int>(s.size()))
	{
		char c = s[r];

		count[c]++;

		while ((count[c] > 1 || r-l+1 > k) &&  l < r)
		{
			count[s[l]]--;
			l++;
		}

		if (r-l+1 == k)
		{
			std::string substring = s.substr(l, k);
			if (!seen[substring]) ans.push_back(substring);

			seen[substring] = true;
		}

		r++;
	}

	return ans;
}
