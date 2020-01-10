#pragma once

#include <vector> 

namespace DataStructures
{

class Trie
{
public:
	struct TrieNode
	{
		TrieNode();

		std::vector<TrieNode*> children;
		bool endOfWord;
	};

	Trie();
	~Trie();

	void insert(const std::wstring& word);

	std::vector<std::wstring> getKClosest(std::wstring& word, int k);

private:
	void insert		(const std::wstring& word, int index, TrieNode* cur);
	void getKClosest(std::wstring& word, int index, std::wstring curSearch, std::vector<std::wstring>& kClosest, TrieNode* cur, int k);

private:
	TrieNode* root;
};

}