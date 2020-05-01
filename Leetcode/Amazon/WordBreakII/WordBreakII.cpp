#include "WordBreakII.h"

using namespace Amazon;

WordBreakII::WordBreakII(std::string & s, std::vector<std::string>& wordDict)
	:	s		(s		 )
	,	wordDict(wordDict)
{
}

std::vector<std::string> WordBreakII::brokenStrings()
{
	if ((s.empty() && !wordDict.empty()) || (!s.empty() && wordDict.empty()))	return {};
	if ( s.empty() &&  wordDict.empty())										return {};
	
	std::vector<bool> dp(s.size(), false);
	
	for (int i = 0; i < dp.size(); ++i)
	    for (const auto& word : wordDict)
	    {
	        if (i - static_cast<int>(word.length()) + 1 < 0) continue;
	
	        if (i - word.size() + 1 == 0 || dp[i - word.size()])
	        {
	            std::string check = s.substr(i - word.size() + 1, word.size());
	            if (check == word) dp[i] = true;
	        }
	    }
	
	if (!dp[dp.size() - 1]) return {};
	
	std::vector<std::string> ans;
	
	getStrings(dp, ans, "", dp.size() - 1);
	
	return ans;
}

void WordBreakII::getStrings(std::vector<bool>& dp, std::vector<std::string>& ans, std::string cur, int i)
{
	if (i < 0)
	{
	    cur.erase(0, 1);
	    ans.push_back(cur);
	    return;
	}
	
	for (const auto& word: wordDict)
	{
	    if (i - static_cast<int>(word.length()) + 1 < 0) continue;
	
	    if (i - word.size() + 1 == 0 || dp[i - word.size()])
	    {
	        std::string check = s.substr(i - word.size() + 1, word.size());
	        if (check == word)
	        {
	            cur.insert(0, check);
	            cur.insert(0, " ");

	            getStrings(dp, ans, cur, i - word.size());
	            
				cur.erase(0, check.size() + 1);
	        }
	    }
	}
}
