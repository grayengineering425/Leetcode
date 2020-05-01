#pragma once
#include <string>

namespace Amazon
{

//https://leetcode.com/discuss/interview-question/330356
class LongestWithoutConsecutive
{
public:
	LongestWithoutConsecutive();

	std::string getLongest(int a, int b, int c);
};

}