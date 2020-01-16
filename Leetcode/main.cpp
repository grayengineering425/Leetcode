#include "Amazon/Zombies/Zombies.h"
#include "Amazon/SearchSuggestion/Suggestion.h"
#include "Amazon/Cities/Cities.h"
#include "Amazon/TwoSum/TwoSum.h"
#include "Amazon/MaxAverageSubtree/MaxAverageSubtree.h"
#include "Amazon/RepairEdges/RepairEdges.h"
#include "Amazon/Spiral/Spiral.h"
#include "Amazon/LongestPalindrome/LongestPalindrome.h"
#include "Amazon/MaxMinPath/MaxMinPath.h"
#include "Amazon/TopBuzzwords/TopBuzzwords.h"

#include <iostream>
#include <string>

using namespace Amazon;

int main()
{
	std::vector<std::string> quotes = {
			"Elmo is the hottest of the season! Elmo will be on every kid's wishlist!"
		,	"The new Elmo dolls are super high quality"
		,	"Expect the Elsa dolls to be very popular this year, Elsa!"
		,	"Elsa and Elmo are the toys I'll be buying for my kids, Elsa is good"
		,	"For parents of older kids, look into buying them a drone"
		,	"Warcraft is slowly rising in popularity ahead of the holiday season"
	};

	std::vector<std::string> toys = {"elmo", "elsa", "legos", "drone", "tablet", "warcraft"};

	TopBuzzwords t(toys, quotes);

	t.topN(2);

	return 0;
}