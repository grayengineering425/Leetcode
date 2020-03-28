#pragma once
#include <vector>

namespace General
{

//https://leetcode.com/problems/course-schedule
class CourseSchedule
{
public:
	CourseSchedule();

	bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);

private:
	bool topSort(std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& finished, int u);
};

}
