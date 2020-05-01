#pragma once
#include <vector>

namespace Amazon
{
//https://leetcode.com/discuss/interview-question/370112
class DistinctSubstringsSizeK
{
public:
	DistinctSubstringsSizeK();

	std::vector<std::string> getSubstrings(const std::string& s, int k);
};

}