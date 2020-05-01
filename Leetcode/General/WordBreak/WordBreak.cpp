#include "WordBreak.h"

using namespace Leetcode;

WordBreak::WordBreak(std::string & s, std::vector<std::string>& wordDict)
	:	s		(s		 )
	,	wordDict(wordDict)
{
}

bool WordBreak::canBeBroken()
{
	if ((s.empty() && !wordDict.empty()) || (!s.empty() && wordDict.empty())) return false;
	if (s.empty() && wordDict.empty()) return true;
	
	std::vector<bool> dp(s.size(), false);
	
	for (int i=0; i<dp.size(); ++i)
	for (const auto& word: wordDict)
	{
	    if (i - static_cast<int>(word.length()) + 1 < 0) continue;
	    
	    if (i - word.size() + 1 == 0 || dp[i - word.size()])
	    {
			std::string check = s.substr(i - word.size() + 1, word.size());
	        if (check == word) dp[i] = true;
	    }
	}
	
	return dp[dp.size()-1];
}
