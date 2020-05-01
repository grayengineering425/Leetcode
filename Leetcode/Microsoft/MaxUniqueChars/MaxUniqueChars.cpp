#include "MaxUniqueChars.h"

using namespace Microsoft;

#include <algorithm>

MaxUniqueChars::MaxUniqueChars() = default;

int MaxUniqueChars::maxLength(std::vector<std::string>& arr)
{
	std::vector<std::vector<int>> count;
	
	for (size_t i=0; i<arr.size(); ++i)
	{
	    bool unique = true;
	    
	    int mask = 0;
	    
	    for (const auto& c: arr[i]  )
	    {
	        int bit = 1;
	        bit = bit << (c - 'a');
	        
	        if ((mask & bit) != 0) { unique = false; break; }
	
	        mask = mask | bit;
	    }
	    
	    if (unique) count.push_back({ mask, static_cast<int>(arr[i].size()) });
	}
	
	int max = 0;
	
	backtrack(count, 0, 0, 0, max);
	
	return max;
}

void MaxUniqueChars::backtrack(std::vector<std::vector<int>>& count, int l, int mask, int length, int& max)
{
	if (l >= static_cast<int>(count.size())){ max = std::max(max, length); return; }
	
	for (size_t i=l; i<count.size(); ++i)
	{
	    if ((count[i][0] & mask) == 0)
	    {
	        int newMask = mask;
	
	        newMask = newMask | count[i][0];
	
	        backtrack(count, i+1, newMask, length + count[i][1], max);
	    }
	
	    backtrack(count, i+1, mask, length, max);
	}
}
