#include "TypeTime.h"

#include <unordered_map>

using namespace Google;

TypeTime::TypeTime() = default;

int TypeTime::calculateTime(std::string keyboard, std::string word)
{
	std::unordered_map<char, int> keyIndex;
	
	for (int i=0; i<keyboard.size(); ++i) keyIndex[keyboard[i]] = i;
	
	int last = 0;
	int cost = 0;
	
	for (int i=0; i<word.size(); ++i)
	{
	    char c = word[i];
	    
	    int index = keyIndex[c];
	    
	    cost += std::abs(last - index);
	    
	    last = index;
	}
	
	return cost;
}
