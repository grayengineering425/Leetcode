#include "KDistinctSubstrings.h"

#include <unordered_map>

using namespace Amazon;

KDistinctSubstrings::KDistinctSubstrings(std::string & S)
	:	s(S)
{
}

int KDistinctSubstrings::getSubstrings(int k)
{
	return getSubstringsHelper(k) - getSubstringsHelper(k-1);
}

int KDistinctSubstrings::getSubstringsHelper(int k)
{
	int ans = 0;
	
	int l = 0;
	int r = 0;
	
	std::unordered_map<char, int> count;

	int numDistinct = 0;

	while (r < s.size())
	{
	    char c = s[r];
	    
	    count[c]++;

		if (count[c] == 1) numDistinct++;
	    
	    while (numDistinct > k && l < r)
	    {
	        count[s[l]]--;

			if (count[s[l]] == 0) numDistinct--;

	        l++;
	    }
	    
	    if (numDistinct > 0) ans += r - l + 1;
	    
	    r++;
	}
	return ans;
}
