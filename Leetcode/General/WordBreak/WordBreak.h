#pragma once
#include <vector>

namespace Leetcode
{

//https://leetcode.com/problems/word-break/

class WordBreak
{
public:
	WordBreak(std::string& s, std::vector<std::string>& wordDict);

	bool canBeBroken();

private:
	std::string					s;
	std::vector<std::string>	wordDict;
};

}
