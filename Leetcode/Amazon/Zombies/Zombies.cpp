#include "Zombies.h"
#include <queue>

using namespace Amazon;

Zombies::Zombies(std::vector<std::vector<int>>& zombieGrid)
	:	zombieGrid(zombieGrid)
{
}

int Zombies::hoursToInfect()
{
	if (zombieGrid.empty()) return 0;

	int hours			= 0;
	int totalZombies	= 0;

	int totalPeople = zombieGrid.size() * zombieGrid.size();

	std::vector<std::vector<bool>> visited(zombieGrid.size(), std::vector<bool>(zombieGrid[0].size(), false));

	std::queue<ZombieCell> zombies;

	std::vector<ZombieCell> zombieMoves =
	{
			{  1,  0, 0 }
		,	{ -1,  0, 0 }
		,	{  0,  1, 0 }
		,	{  0, -1, 0 }
	};

	for (int i=0; i<zombieGrid	 .size(); ++i)
	for (int j=0; j<zombieGrid[i].size(); ++j)
	{
		if (zombieGrid[i][j] == 1){ zombies.push({ i, j, 0 }); totalZombies++; }
	}

	while (!zombies.empty() && totalZombies < totalPeople)
	{
		auto cur = zombies.front();
		zombies.pop();

		auto curDepth = cur.depth;

		if (curDepth > hours) hours = curDepth;

		for (const auto& move: zombieMoves)
		{
			auto zombie		= cur + move;
			zombie.depth	= cur.depth + 1;

			if (zombie.i >= 0 && zombie.i < zombieGrid.size() && zombie.j >= 0 && zombie.j < zombieGrid[zombie.i].size() && !visited[zombie.i][zombie.j] && zombieGrid[zombie.i][zombie.j] == 0)
			{
				visited[zombie.i][zombie.j] = true;

				zombies.push(zombie);
				
				totalZombies++;
			}
		}
	}

	return hours;
}
