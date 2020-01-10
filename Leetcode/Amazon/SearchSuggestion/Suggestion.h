#pragma once
#include "DataStructures/Trie/Trie.h"

#include <vector>

namespace Amazon
{

using namespace DataStructures;

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