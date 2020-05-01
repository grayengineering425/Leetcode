#pragma once
#include <vector>

namespace Amazon
{

class DiceRollsWithSum
{
public:
	DiceRollsWithSum();

	int numRollsToTarget(int d, int f, int target);
};

}