#include "Amazon/Zombies/Zombies.h"
#include "Amazon/SearchSuggestion/Suggestion.h"

#include <iostream>

using namespace Amazon;

int main()
{
	std::wstring searchWord					= L"tatiana";
	std::vector<std::wstring> suggestions	= { L"havana" };

	Suggestion s(searchWord, suggestions);

	auto c = s.suggestedProducts();

	return 0;
}