#pragma once
#include <vector>

namespace Amazon
{

struct ZombieCell
{
	ZombieCell(int i, int j, int depth)
		:	i	 (i)
		,	j	 (j)
		,	depth(depth)
	{
	}

	ZombieCell operator+(const ZombieCell& rhs)
	{
		ZombieCell z(this->i, this->j, this->depth);
		z.i += rhs.i;
		z.j += rhs.j;

		return z;
	}

	int i;
	int j;
	int depth;
};

class Zombies
{
public:
	Zombies(std::vector<std::vector<int>>& zombieGrid);

	int hoursToInfect();

private:
	std::vector<std::vector<int>> zombieGrid;
};

}