#pragma once
#include <vector>

namespace Microsoft
{
//https://leetcode.com/problems/meeting-rooms-ii/
class MaxUniqueChars
{
public:
	MaxUniqueChars();

	int maxLength(std::vector<std::string>& arr);

private:
	void backtrack(std::vector<std::vector<int>>& count, int l, int mask, int length, int& max);
};

}
