#pragma once
#include <vector>
#include <queue>

namespace General
{
//https://leetcode.com/problems/course-schedule-ii
class CourseScheduleII
{
public:
	CourseScheduleII();

	std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);

private:
	bool topSort(std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& finished, std::queue<int>& sorted, int u);
};

}
