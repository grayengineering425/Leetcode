#include "DataStructures/Trie/Trie.h"

using namespace DataStructures;

Trie::TrieNode::TrieNode()
	:	children	(26, nullptr)
	,	endOfWord	(false)
{
}

Trie::Trie()
{
	root = new TrieNode();
}

Trie::~Trie()
{
}

void Trie::insert(const std::wstring & word)
{
	if (word.empty()) return;

	TrieNode* cur = root;

	insert(word, 0, root);
}

std::vector<std::wstring> Trie::getKClosest(std::wstring & word, int k)
{
	TrieNode* cur = root;

	std::vector<std::wstring> kClosest;

	std::wstring curSearch = L"";

	getKClosest(word, 0, curSearch, kClosest, cur, k);

	return kClosest;
}

void Trie::insert(const std::wstring& word, int index, TrieNode* cur)
{
	if (index >= (int)word.size())
	{
		cur->endOfWord = true;
		return;
	}

	int c = word[index] - 'a';

	if (!cur->children[c]) cur->children[c] = new TrieNode();

	insert(word, index + 1, cur->children[c]);
}

void Trie::getKClosest(std::wstring& word, int index, std::wstring curSearch, std::vector<std::wstring>& kClosest, TrieNode* cur, int k)
{
	if (index < (int)word.size())
	{
		char c = word[index] - 'a';

		if (!cur->children[c]) return;

		getKClosest(word, index + 1, curSearch + word[index], kClosest, cur->children[c], k);
	}
	else
	{
		if ((int)kClosest.size() >= k) return;

		if (cur->endOfWord) kClosest.push_back(curSearch);

		for (size_t i=0; i<cur->children.size(); ++i)
		{
			if (cur->children[i])
			{
				wchar_t addition = L'a' + (wchar_t)i;

				getKClosest(word, index, curSearch + addition, kClosest, cur->children[i], k);
			}
		}
	}
}