#include "Amazon/Zombies/Zombies.h"
#include "Amazon/SearchSuggestion/Suggestion.h"
#include "Amazon/Cities/Cities.h"
#include "Amazon/TwoSum/TwoSum.h"
#include "Amazon/MaxAverageSubtree/MaxAverageSubtree.h"
#include "Amazon/RepairEdges/RepairEdges.h"

#include <iostream>

using namespace Amazon;

int main()
{
	std::vector<std::wstring> products = { L"mobile",L"mouse",L"moneypot",L"monitor",L"mousepad" };
	std::wstring word = L"mouse";

	Suggestion s(word, products);

	s.suggestedProducts();

	return 0;
}