#include "Suggestion.h"

using namespace Amazon;

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

	for (size_t i=0; i<word.size(); ++i)
	{
		curWord += word[i];

		suggestions.push_back(t.getKClosest(curWord, 3));
	}

	return suggestions;
}
