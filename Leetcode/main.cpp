#include "Amazon/Amazon.h"

#include <iostream>
#include <string>

using namespace Amazon;

int main()
{
	std::vector<std::vector<char>> map = {	{'S', 'O', 'O', 'O'},
											{'D', 'O', 'D', 'O'},
											{'O', 'O', 'O', 'O'},
											{'X', 'D', 'D', 'O'} };

	TreasureIsland t(map);

	std::cout << t.minSteps2() << std::endl;

	return 0;
}