#pragma once
#include <unordered_map>

namespace Amazon
{
//https://leetcode.com/discuss/interview-question/373006
class FavoriteGenres
{
public:
	FavoriteGenres();

	std::unordered_map<std::string, std::vector<std::string>> getFavorites(std::unordered_map<std::string, std::vector<std::string>>& userSongs, std::unordered_map<std::string, std::vector<std::string>>& genres);
};

}