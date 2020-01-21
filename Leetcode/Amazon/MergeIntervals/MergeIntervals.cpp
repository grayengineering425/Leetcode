#include "MergeIntervals.h"

#include <queue>
#include <algorithm>

using namespace Amazon;

MergeIntervals::MergeIntervals(std::vector<std::vector<int>>& intervals)
	:	intervals(intervals)
{
}

std::vector<std::vector<int>> MergeIntervals::merge()
{
	std::vector<std::vector<int>> ans;
        
	auto compare = [this](std::vector<int>& lhs, std::vector<int>& rhs)
	{
		return lhs[0] > rhs[0];
	};
	
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> pq(compare);
	
	for (const auto& interval: intervals) pq.push(interval);
	
	while (!pq.empty())
	{
	    auto cur = pq.top();
	    pq.pop();
	    
	    if (pq.empty()) ans.push_back(cur);
	    else
	    {
	        auto next = pq.top();
	        
	        if (std::max(cur[0], next[0]) <= std::min(cur[1], next[1]))
	        {
	            pq.pop();
	            
	            pq.push({ std::min(cur[0], next[0]), std::max(cur[1], next[1])});
	        }
	        else ans.push_back(cur);
	    }
	}
        return ans;
}
