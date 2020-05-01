#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>
#include <memory>

namespace Leetcode
{

struct compare
{
	bool operator ()(const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs)
	{
		if (lhs.second == rhs.second)
		{
			int i = 0;

			while (i < lhs.first.size() && i < rhs.first.size())
			{
				char cl = lhs.first[i];
				char cr = rhs.first[i];

				if (cl != cr) return cl > cr;

				i++;
			}

			return lhs.first.size() > rhs.first.size();
		}

		return lhs.second < rhs.second;
	};
};

struct WeightedTrie
{
	WeightedTrie()
		:	children	(27, nullptr)
		,	endOfWord	(false)
	{
	}
	
	std::vector<std::shared_ptr<WeightedTrie>>	children;
	bool										endOfWord;
};

class AutoComplete
{
public:
	AutoComplete(std::vector<std::string>& words, std::vector<int>& times);

	std::vector<std::string> input(char c);

private:
	void insert(std::string& word, bool increment);
	void insert(std::shared_ptr<WeightedTrie>& root, std::string& word, int index);

	void getClosest(std::shared_ptr<WeightedTrie>& root, std::string& word, int index, std::string curWord, std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare>& pq);

private:
	std::unordered_map<std::string, int> sentenceWeights;

	std::shared_ptr<WeightedTrie> root;

	std::string curSearch;
};

}