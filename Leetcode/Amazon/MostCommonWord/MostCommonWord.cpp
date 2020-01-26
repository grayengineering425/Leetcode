#include "MostCommonWord.h"

#include <unordered_map>
#include <cctype>

using namespace Amazon;

MostCommonWord::MostCommonWord(std::string paragraph, std::vector<std::string>& banned)
	:	paragraph	(paragraph)
	,	banned		(banned)
{
}

std::string MostCommonWord::getMostCommon()
{
	std::unordered_map<std::string, int>  count;
	std::unordered_map<std::string, bool> mBanned;
	
	int max          = 0;
	std::string maxS = "";
	
	for (const auto& s: banned) mBanned[s] = true;
	
	int i=0;
	
	std::string curString = "";
	
	while (i <= paragraph.size())
	{
	    char c = i == paragraph.size() ? '!' : paragraph[i];
	    
	    if (c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.' || c == ' ')
	    {
	        if (mBanned.find(curString) == mBanned.end() && !curString.empty())
	        {
	            count[curString]++;
	            
	            if (count[curString] > max){ max = count[curString]; maxS = curString; }
	        }
	        
	        curString = "";
	    }
	    else
	    {
	        curString += std::tolower(c);
	    }
	    
	    i++;
	}
	
	return maxS;
}
