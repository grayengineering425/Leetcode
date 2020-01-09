#include "Suggestion.h"

using namespace Amazon;

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

std::vector<std::wstring> Trie::getKClosest(std::wstring & word)
{
	TrieNode* cur = root;

	std::vector<std::wstring> kClosest;

	std::wstring curSearch = L"";

	getKClosest(word, 0, curSearch, kClosest, cur);

	return kClosest;
}

void Trie::insert(const std::wstring& word, int index, TrieNode * cur)
{
	if (index >= word.size())
	{
		cur->endOfWord = true;
		return;
	}

	int c = word[index] - 'a';

	if (!cur->children[c]) cur->children[c] = new TrieNode();

	insert(word, index + 1, cur->children[c]);
}

void Trie::getKClosest(std::wstring& word, int index, std::wstring curSearch, std::vector<std::wstring>& kClosest, TrieNode* cur)
{
	if (index < word.size())
	{
		char c = word[index] - 'a';

		if (!cur->children[c]) return;

		getKClosest(word, index + 1, curSearch + word[index], kClosest, cur->children[c]);
	}
	else
	{
		if (kClosest.size() >= 3) return;

		if (cur->endOfWord) kClosest.push_back(curSearch);

		for (int i=0; i<cur->children.size(); ++i)
		{
			if (cur->children[i])
			{
				wchar_t addition = L'a' + i;

				getKClosest(word, index, curSearch + addition, kClosest, cur->children[i]);
			}
		}
	}
}

Suggestion::Suggestion(std::wstring & word, std::vector<std::wstring>& products)
	:	word(word)
{
	for (const auto& product: products) t.insert(product);
}

Suggestion::~Suggestion()
{
}

std::vector<std::vector<std::wstring>> Suggestion::suggestedProducts()
{
	std::vector<std::vector<std::wstring>> suggestions;

	std::wstring curWord = L"";

	for (int i=0; i<word.size(); ++i)
	{
		curWord += word[i];

		suggestions.push_back(t.getKClosest(curWord));
	}

	return suggestions;
}
