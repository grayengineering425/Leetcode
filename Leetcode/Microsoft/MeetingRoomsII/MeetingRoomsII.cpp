#include "MeetingRoomsII.h"

#include <algorithm>
#include <queue>

using namespace Microsoft;

MeetingRoomsII::MeetingRoomsII() = default;

int MeetingRoomsII::minMeetingRooms(std::vector<std::vector<int>>& intervals)
{
	if (intervals.empty()) return 0;
	
	auto compare = [] (const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
	    return lhs[0] < rhs[0];
	};
	
	std::sort(intervals.begin(), intervals.end(), compare);
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	
	int count = 0;
	
	for (size_t i=0; i<intervals.size(); ++i)
	{
	    auto curInterval = intervals[i];
	    
	    if (pq.empty()) count++;
	    
	    else
	    {
	        auto nextFree = pq.top();
	        
	        if (curInterval[0] >= pq.top()) pq.pop();
	        
	        else count++;
	    }
	    
	    pq.push(curInterval[1]);
	}
	
	return count;
}
