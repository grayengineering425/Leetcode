#include "Amazon/Amazon.h"
#include "General/General.h"
#include "Microsoft/Microsoft.h"
#include "Google/Google.h"

#include <iostream>
#include <string>
#include <vector>

using namespace Amazon;
using namespace General;
using namespace Microsoft;
using namespace Google;
using namespace DataStructures;

using namespace std;

#include <unordered_map>
#include <stack>
#include <unordered_set>

//battleship
//min of max altitudes?
//favorite genres?

int main()
{
	std::unordered_map<std::string, std::vector<std::string>> userSongs;

	userSongs["David"] = { "song1", "song2", "song3", "song4", "song8" };
	userSongs["Emma" ] = { "song5", "song6", "song7" };

	std::unordered_map<std::string, std::vector<std::string>> songGenres;
	//songGenres["Rock"	] = { "song1", "song3" };
	//songGenres["Dubstep"] = { "song7" };
	//songGenres["Techno"	] = { "song2", "song4" };
	//songGenres["Pop"	] = { "song5", "song6" };
	//songGenres["Jazz"	] = { "song8", "song9" };

	FavoriteGenres f;

	f.getFavorites(userSongs, songGenres);
}