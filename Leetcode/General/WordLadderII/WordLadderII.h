#pragma once
#include <vector>

namespace General
{

//https://leetcode.com/problems/word-ladder-ii/

class WordLadderII
{
public:
	WordLadderII(std::string& begin, std::string& end, std::vector<std::string>& wordList);

	std::vector<std::vector<std::string>> findLadders();

private:
	bool isOneOff	(const std::string& lhs, const std::string& rhs);
	void backtrack	(std::string curWord, std::string& endWord, std::vector<std::string>& words, std::vector<bool> seen, int count, std::vector<std::string> curPath, std::vector<std::string>& path);

private:
	std::string					begin;
	std::string					end;
	std::vector<std::string>	wordList;
};

}
