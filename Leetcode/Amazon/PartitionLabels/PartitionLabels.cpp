#include "PartitionLabels.h"

#include <unordered_map>

using namespace Amazon;

ParitionLabels::ParitionLabels(std::string & S)
	:	S(S)
{
}

std::vector<int> ParitionLabels::partitionLabels()
{
	std::unordered_map<char, int> last;
	
	for (int i=S.size()-1; i>=0; --i)
	{
	    char c = S[i];
	    
	    if (last.find(c) == last.end()) last[c] = i;
	}
	
	std::vector<int> ans;
	
	size_t l    = 0;
	size_t r    = 0;
	int lastC   = 0;
	
	while (r < S.size())
	{
	    char c = S[r];
	    
	    int curLast = last[c];
	    
	    if (curLast > lastC) lastC = curLast;
	    
	    if (r == lastC || r == S.size() - 1){ ans.push_back(r - l + 1); l = r + 1; }
	    
	    r++;
	}
	
	return ans;
}
