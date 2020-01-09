#pragma once

#include <vector>

namespace Amazon
{

class Trie
{
public:
	struct TrieNode
	{
		TrieNode()
			:	children	(26, nullptr)
			,	endOfWord	(false)
		{
		}

		std::vector<TrieNode*> children;
		bool endOfWord;
	};

	Trie();
	~Trie();

	void insert(const std::wstring& word);

	std::vector<std::wstring> getKClosest(std::wstring& word);

private:
	void insert		(const std::wstring& word, int index, TrieNode* cur);
	void getKClosest(std::wstring& word, int index, std::wstring curSearch, std::vector<std::wstring>& kClosest, TrieNode* cur);

private:
	TrieNode* root;
};

class Suggestion
{
public:
	Suggestion(std::wstring& word, std::vector<std::wstring>& products);
	~Suggestion();

	std::vector<std::vector<std::wstring>> suggestedProducts();

private:

	std::wstring				word;
	std::vector<std::wstring>	products;

	Trie t;
};

}