#include "WordLadderII.h"

#include <queue>
#include <unordered_map>
#include <map>

using namespace General;

WordLadderII::WordLadderII(std::string & begin, std::string & end, std::vector<std::string>& wordList)
	:	begin	(begin)
	,	end		(end)
	,	wordList(wordList)
{
}

std::vector<std::vector<std::string>> WordLadderII::findLadders()
{
	if (wordList.empty() || std::find(wordList.begin(), wordList.end(), end) == wordList.end()) return {};

	std::vector<std::vector<std::string>> shortestLadders;

	int shortest = INT_MAX;

	std::unordered_map<std::string, int> shortestPathBegin;
	std::unordered_map<std::string, int> shortestPathEnd;

	std::map<std::vector<std::string>, bool> seenPath;

	std::queue<std::pair<std::string, int>> beginQ;
	std::queue<std::pair<std::string, int>> endQ;

	beginQ	.push(std::make_pair(begin	, 1));
	endQ	.push(std::make_pair(end	, 1));

	while (!beginQ.empty() && !endQ.empty())
	{
		auto curBegin	= beginQ.front();
		auto curEnd		= endQ	.front();

		std::string beginStep	= curBegin.first; 
		std::string endStep		= curEnd.first;

		int beginCount	= curBegin	.second;
		int endCount	= curEnd	.second;

		beginQ	.pop();
		endQ	.pop();

		if (shortestPathBegin	.find(beginStep	) == shortestPathBegin	.end()) shortestPathBegin	[beginStep] = beginCount;
		if (shortestPathEnd		.find(endStep	) == shortestPathEnd	.end()) shortestPathEnd		[endStep]	= endCount;

		if (shortestPathBegin.find(endStep) != shortestPathBegin.end() && endCount + shortestPathBegin[endStep] <= shortest)
		{
			if (shortest < endCount + shortestPathBegin[endStep]) shortestLadders.clear();

			shortest = endCount + shortestPathBegin[endStep];

			wordList.push_back(begin);

			std::vector<bool> seen(wordList.size(), false);

			std::vector<std::string> beginPath;
			backtrack(begin	,	endStep, wordList, seen, shortestPathBegin[endStep],	{}, beginPath	);
			std::vector<std::string> endPath;
			backtrack(end	,	endStep, wordList, seen, endCount,						{}, endPath		);

			std::vector<std::string> path;

			path.insert(path.begin(), endPath	.rbegin() + 1,	endPath		.rend());
			path.insert(path.begin(), beginPath	.begin(),		beginPath	.end());

			if (!seenPath[path]) shortestLadders.push_back(path);

			seenPath[path] = true;

			wordList.pop_back();
		}

		if (shortestPathEnd.find(beginStep) != shortestPathEnd.end() && beginCount + shortestPathEnd[beginStep] <= shortest)
		{
			if (shortest < beginCount + shortestPathEnd[beginStep]) shortestLadders.clear();
			
			shortest = beginCount + shortestPathEnd[beginStep];

			wordList.push_back(begin);

			std::vector<bool> seen(wordList.size(), false);

			std::vector<std::string> endPath;
			backtrack(end,	 beginStep,	wordList, seen, shortestPathEnd[beginStep],	{}, endPath	);
			std::vector<std::string> beginPath;
			backtrack(begin, beginStep,	wordList, seen, beginCount,					{}, beginPath);

			std::vector<std::string> path;

			path.insert(path.begin(), endPath	.rbegin() + 1,	endPath		.rend());
			path.insert(path.begin(), beginPath	.begin(),		beginPath	.end());

			if (!seenPath[path]) shortestLadders.push_back(path);

			seenPath[path] = true;

			wordList.pop_back();
		}

		for (const auto& word : wordList)
		{
			if (shortestPathBegin	.find(word) == shortestPathBegin.end() && isOneOff(word, beginStep	)) beginQ	.push(std::make_pair(word, beginCount	+ 1));
			if (shortestPathEnd		.find(word) == shortestPathEnd	.end() && isOneOff(word, endStep	)) endQ		.push(std::make_pair(word, endCount		+ 1));
		}
	}

	return shortestLadders;
}

bool WordLadderII::isOneOff(const std::string& lhs, const std::string& rhs)
{
	if (lhs.size() != rhs.size()) return false;
	int count = 0;
	for (int i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i] != rhs[i]) count++;

		if (count > 1) return false;
	}
	return true;
}

void WordLadderII::backtrack(std::string curWord, std::string & endWord, std::vector<std::string>& words, std::vector<bool> seen, int count, std::vector<std::string> curPath, std::vector<std::string>& path)
{
	if (curPath.size() > count)												return;
	if (curWord == endWord && curPath.size() == count){	path =  curPath;	return; }

	for (int i=0; i<words.size(); ++i)
	{
		std::string word = words[i];

		if (!seen[i] && isOneOff(curWord, word))
		{
			curPath.push_back(word);
			
			seen[i] = true;

			backtrack(word, endWord, words, seen, count, curPath, path);
			
			seen[i] = false;

			curPath.pop_back();
		}
	}

	return;
}
