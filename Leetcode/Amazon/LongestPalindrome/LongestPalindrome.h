#pragma once
#include <string>

namespace Amazon
{

class LongestPalindrome
{
public:
	LongestPalindrome(std::string& s);

	std::string longestPalindrome();

private:
	std::string& s;
};

}