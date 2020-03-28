#include "OddEven.h"

#include <map>

using namespace Google;

OddEven::OddEven() = default;

int OddEven::oddEvenJumps(std::vector<int>& A)
{
	if (A.size() < 2) return A.size();
	
	std::vector<std::vector<int>> dp(A.size(), std::vector<int>(2, 0));
	
	std::map<int, std::vector<int>> sortedKeys;
	
	for (int i = 0; i < static_cast<int>(A.size()); ++i) sortedKeys[A[i]].push_back(i);
	
	auto begin	= sortedKeys.begin	();
	auto end	= sortedKeys.end	();
	
	for (int i=0; i<static_cast<int>(dp.size())-1; ++i)
	{
	    int minIndex = -1;
	    int maxIndex = -1;
	
	    auto curValue = sortedKeys.find(A[i]);
	    auto minValue = curValue;
	    auto maxValue = curValue;
	
	    while (minIndex == -1)
	    {
	        int index = 0;
	
	        while (index < static_cast<int>(minValue->second.size()) && minIndex == -1)
	        {
	            if (minValue->second[index] > i) minIndex = minValue->second[index];
	
	            ++index;
	        }
	
	        if (minValue == begin) break;
	
	        --minValue;
	    }
	
	    while (maxIndex == -1)
	    {
	        int index = 0;
	
	        while (index < static_cast<int>(maxValue->second.size()) && maxIndex == -1)
	        {
	            if (maxValue->second[index] > i) maxIndex = maxValue->second[index];
	
	            ++index;
	        }
	        
	        ++maxValue;
	        
	        if (maxValue == end) break;
	    }
	
	    if (minIndex > -1 && dp[i][0] > 0	) dp[minIndex][1] += dp[i][0];
	    if (maxIndex > -1					) dp[maxIndex][0] += dp[i][1] + 1;
	}
	
	return dp[dp.size()-1][0] + dp[dp.size()-1][1] + 1;
}
