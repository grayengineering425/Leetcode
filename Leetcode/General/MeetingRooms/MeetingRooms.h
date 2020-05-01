#pragma once
#include <vector>

namespace Leetcode { namespace General
{

//https://leetcode.com/problems/meeting-rooms-ii/

class MeetingRooms
{
public:
	MeetingRooms(std::vector<std::vector<int>>& meetings);

	int minMeetingRooms();

private:
	std::vector<std::vector<int>> meetings;
};

}}