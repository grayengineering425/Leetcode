#include "LongestPalindrome.h"

#include <vector>
#include <algorithm>

using namespace Amazon;

LongestPalindrome::LongestPalindrome(std::string& s)
	:	s(s)
{
}

std::string LongestPalindrome::longestPalindrome()
{
	std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));

	int max						= 0;
	std::string maxPalindrome	= "";


	for (int i=0; i<dp.size(); ++i) dp[i][i] = 1;

	for (int dist=1; dist<s.size(); ++dist)
	{
		int l = 0;
		
		while (l + dist < s.size())
		{
			int r = l + dist;

			if (s[l] == s[r])
			{
				if (dist == 1)			dp[l][r] = 2; else
				if (dp[l+1][r-1] == 0)	dp[l][r] = 0;
				else					dp[l][r] = dp[l+1][r-1] + 2;

				if (dp[l][r] > max)
				{
					max = dp[l][r];
					maxPalindrome = s.substr(l, dp[l][r]);
				}
			}

			l++;
		}
	}
	return maxPalindrome;
}
