#pragma once
#include <vector>

namespace Amazon
{
//https://leetcode.com/discuss/interview-question/370157
class KDistinctSubstrings
{
public:
	KDistinctSubstrings(std::string& s);

	int getSubstrings(int k);

private:
	int getSubstringsHelper(int k);

private:
	std::string s;
};

}