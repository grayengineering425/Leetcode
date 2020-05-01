#pragma once
#include <vector>

namespace Amazon
{

class SnakesAndLadders
{
public:
	SnakesAndLadders();

	int snakesAndLadders(std::vector<std::vector<int>>& board);

private:
	std::vector<int> increment(int i, int j, int N, int count);
	std::vector<int> findSpace(int N, int num);
};

};