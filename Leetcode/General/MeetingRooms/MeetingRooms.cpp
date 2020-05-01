#include "MeetingRooms.h"

#include <queue>

using namespace Leetcode;
using namespace General;

MeetingRooms::MeetingRooms(std::vector<std::vector<int>>& meetings)
	:	meetings(meetings)
{
}

int MeetingRooms::minMeetingRooms()
{
	if (meetings.empty()) return 0;
	
	auto compare = [] (const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
	    return lhs[0] < rhs[0];
	};
	
	std::sort(meetings.begin(), meetings.end(), compare);
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	
	int count = 0;
	
	for (int i=0; i< meetings.size(); ++i)
	{
	    auto curMeeting = meetings[i];
	    
	    if (pq.empty()) count++;
	    
	    else
	    {
	        auto nextFree = pq.top();
	        
	        if (curMeeting[0] >= pq.top()) pq.pop();
	        
	        else count++;
	    }
	    
	    pq.push(curMeeting[1]);
	}
	
	return count;
}
