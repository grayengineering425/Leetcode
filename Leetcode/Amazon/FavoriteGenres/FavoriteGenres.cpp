#include "FavoriteGenres.h"

using namespace Amazon;

FavoriteGenres::FavoriteGenres() = default;

std::unordered_map<std::string, std::vector<std::string>> FavoriteGenres::getFavorites(std::unordered_map<std::string, std::vector<std::string>>& userSongs, std::unordered_map<std::string, std::vector<std::string>>& genres)
{
	std::unordered_map<std::string, std::string> songToGenre;

	for (const auto& genre	: genres		)
	for (const auto& song	: genre.second	)
	{
		songToGenre[song] = genre.first;
	}

	std::unordered_map<std::string, std::vector<std::string>> favoriteGenres;

	for (const auto& user: userSongs)
	{
		favoriteGenres[user.first];		//needed in case none of the songs are mapped

		std::unordered_map<std::string, int> genreCount;
		int max = 0;
		
		for (const auto& song: user.second	)
		{
			if (songToGenre.find(song) != songToGenre.end())
			{
				genreCount[songToGenre[song]]++;

				if (genreCount[songToGenre[song]] > max)
				{
					favoriteGenres[user.first].clear();
					favoriteGenres[user.first].push_back(songToGenre[song]);

					max = genreCount[songToGenre[song]];
				}
				else if (genreCount[songToGenre[song]] == max)
				{
					favoriteGenres[user.first].push_back(songToGenre[song]);
				}
			}
		}
	}

	return favoriteGenres;
}
