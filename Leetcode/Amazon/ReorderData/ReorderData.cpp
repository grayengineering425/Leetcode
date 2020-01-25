#include "ReorderData.h"

#include <algorithm>

using namespace Amazon;

ReorderData::ReorderData(std::vector<std::string>& logs)
	:	logs(logs)
{
}

std::vector<std::string> ReorderData::reorder()
{
	std::stable_sort(logs.begin(), logs.end(), [](const std::string& lhs, const std::string& rhs)
	{
	    size_t l = 0;
		size_t r = 0;
	    
	    std::string lIdentifier = "";
	    std::string rIdentifier = "";
	    
	    while (lhs[l] != ' ' && rhs[r] != ' ')
	    {
	        if (lhs[l] != ' '){ lIdentifier += lhs[l]; l++; }
	        if (rhs[l] != ' '){ rIdentifier += rhs[r]; r++; }
	    }
	    
	    while (lhs[l] != ' '){ lIdentifier += lhs[l]; l++; }
	    while (rhs[r] != ' '){ rIdentifier += rhs[r]; r++; }
	    
	    l++; r++;
	    
	    if (lhs[l] >= '0' && lhs[l] <= '9' && rhs[r] >= '0' && rhs[r] <= '9') return false;
	    if (lhs[l] >= '0' && lhs[l] <= '9' && rhs[r] >= 'a' && rhs[r] <= 'z') return false;
	    if (lhs[l] >= 'a' && lhs[l] <= 'z' && rhs[r] >= '0' && rhs[r] <= '9') return true;
	    
	    while (l < lhs.size() && r < rhs.size())
	    {
	        if (lhs[l] == rhs[r]){ l++; r++; continue; }
	        
	        return lhs[l] < rhs[r];
	    }
	    
	    return lIdentifier < rIdentifier;
	});
	
	return logs;
}
