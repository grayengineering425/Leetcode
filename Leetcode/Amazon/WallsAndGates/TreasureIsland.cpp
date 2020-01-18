#include "TreasureIsland.h"

#include <queue>
#include <tuple>

using namespace Amazon;

TreasureIsland::TreasureIsland(std::vector<std::vector<char>>& map)
	:	map(map)
{
}

int TreasureIsland::minSteps()
{
	if (map.empty()) return -1;

	std::queue<std::tuple<int, int, int>> q;

	for (size_t i=0; i<map		.size(); ++i)
	for (size_t j=0; j<map[i]	.size(); ++j)
	{
		if (map[i][j] == 'X'){ q.push(std::make_tuple(i, j, 0)); break; }
	}

	std::vector<std::vector<int>> moves =
	{
			{  0,  1 }
		,   {  0, -1 }
		,   {  1,  0 }
		,   { -1,  0 }
	};

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int curI = std::get<0>(cur);
		int curJ = std::get<1>(cur);
		int curD = std::get<2>(cur);

		if (curI == 0 && curJ == 0) return curD;

		for (const auto& move: moves)
		{
			int nextI = curI + move[0];
			int nextJ = curJ + move[1];

			if (nextI > -1 && nextI < (int)map.size() && nextJ > -1 && nextJ < (int)map[nextI].size() && map[nextI][nextJ] != 'D' && map[nextI][nextJ] != 'V')
			{
				map[nextI][nextJ] = 'V';

				q.push(std::make_tuple(nextI, nextJ, curD + 1));
			}
		}
	}
	return -1;
}

int TreasureIsland::minSteps2()
{
	if (map.empty()) return -1;

	int min = INT_MAX;

	std::queue<std::tuple<int, int, int>> q;

	for (size_t i=0; i<map		.size(); ++i)
	for (size_t j=0; j<map[i]	.size(); ++j)
	{
		if (map[i][j] == 'X'){ q.push(std::make_tuple(i, j, 0)); break; }
	}

	std::vector<std::vector<int>> moves =
	{
			{  0,  1 }
		,   {  0, -1 }
		,   {  1,  0 }
		,   { -1,  0 }
	};

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int curI = std::get<0>(cur);
		int curJ = std::get<1>(cur);
		int curD = std::get<2>(cur);

		for (const auto& move: moves)
		{
			int nextI = curI + move[0];
			int nextJ = curJ + move[1];

			if (nextI > -1 && nextI < (int)map.size() && nextJ > -1 && nextJ < (int)map[nextI].size() && map[nextI][nextJ] != 'D' && map[nextI][nextJ] != 'V')
			{
				if (map[nextI][nextJ] == 'S') min = std::min(min, curD + 1);

				map[nextI][nextJ] = 'V';

				q.push(std::make_tuple(nextI, nextJ, curD + 1));
			}
		}
	}
	return min;
}
