#include "AutoComplete.h"

using namespace Leetcode;

AutoComplete::AutoComplete(std::vector<std::string>& words, std::vector<int>& weights)
	:	root(std::make_shared<WeightedTrie>())
{
	for (int i=0; i<words.size(); ++i)
	{
		std::string word	= words		[i];
		int weight			= weights	[i];

		sentenceWeights[word] = weight;

		insert(word, false);
	}
}

std::vector<std::string> AutoComplete::input(char c)
{
	if (c == '#')
	{
		insert(curSearch, true);

		curSearch = "";

		return {};
	}

	curSearch += c;

	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare> pq;

	getClosest(root, curSearch, 0, "", pq);

	std::vector<std::string> closest;

	int count = 0;

	while (count < 3 && !pq.empty())
	{
		auto top = pq.top();
		pq.pop();

		closest.push_back(top.first);

		count++;
	}

	return closest;
}

void AutoComplete::insert(std::string & word, bool increment)
{
	if (increment) sentenceWeights[word]++;

	insert(root, word, 0);
}

void AutoComplete::insert(std::shared_ptr<WeightedTrie>& root, std::string & word, int index)
{
	if (!root) return;

	if (index >= word.size())
	{
		root->endOfWord = true;
		return;
	}

	char c = word[index];

	int cIndex = c == ' ' ? 26 : c - 'a';

	if (!root->children[cIndex]) root->children[cIndex] = std::make_shared<WeightedTrie>();

	insert(root->children[cIndex], word, index+1);
}

void AutoComplete::getClosest(std::shared_ptr<WeightedTrie>& root, std::string &word, int index, std::string curWord, std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare>& pq)
{
	if (root->endOfWord && index >= word.size()) pq.push(std::make_pair(curWord, sentenceWeights[curWord]));

	if (index >= word.size())
	{
		for (int i=0; i<root->children.size(); ++i)
		{
			auto child = root->children[i];
			if (!child) continue;

			std::string nextWord = curWord;

			nextWord += i == 26 ? ' ' : 'a' + i;

			getClosest(child, word, index, nextWord, pq);
		}
	}

	else
	{
		char c = word[index];

		int cIndex = c == ' ' ? 26 : c - 'a';

		std::string nextWord = curWord;
		nextWord += c;

		if (root->children[cIndex]) getClosest(root->children[cIndex], word, index+1, nextWord, pq);
	}
}
