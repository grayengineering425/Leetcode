#include "MagicSquare.h"

using namespace Leetcode;
using namespace Google;

MagicSquare::MagicSquare() = default;

std::vector<std::vector<int>> MagicSquare::getMagicSquare(int n)
{
	std::vector<std::vector<int>> square(n, std::vector<int>(n, 0));

	int i = n/2;
	int j = n-1;

	int num = 1;

	while (num<=n*n)
	{
		if (i == -1 && j == n)
		{
			i = 0;
			j = n-2;
		}

		else
		{
			if (i == -1) i = n-1;
			if (j ==  n) j = 0;
		}

		if (square[i][j])
		{
			++i;
			j -= 2;
			continue;
		}

		square[i][j] = num++;

		++j;
		--i;
	}

	return square;
}
