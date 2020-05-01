#pragma once
#include <vector>

namespace Amazon
{

//https://leetcode.com/problems/word-break-ii/

class WordBreakII
{
public:
	WordBreakII(std::string& s, std::vector<std::string>& wordDict);

	std::vector<std::string> brokenStrings();

private:
	void getStrings(std::vector<bool>& dp, std::vector<std::string>& ans, std::string cur, int index);

private:
	std::string					s;
	std::vector<std::string>	wordDict;
};

}
