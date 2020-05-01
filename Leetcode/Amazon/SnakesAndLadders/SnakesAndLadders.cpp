#include "SnakesAndLadders.h"

#include <queue>

using namespace Amazon;

SnakesAndLadders::SnakesAndLadders() = default;

int SnakesAndLadders::snakesAndLadders(std::vector<std::vector<int>>& board)
{
	std::queue<std::vector<int>> moves;
	
	int N = static_cast<int>(board.size());
	
	moves.push( { N - 1, 0, 0, 0, 0 } );
	
	while (!moves.empty())
	{
	    auto curMove = moves.front();
	    moves.pop();
	    
	    int i = curMove[0];
	    int j = curMove[1];
	    int m = curMove[2];
	    
	    if (i == 0 && j == 0)
			return m;
	    
	    if (board[i][j] == -1)
	    {
	        auto moveOne    = increment(i,              j,              N - 1, 1);
	        auto moveTwo    = increment(moveOne  [0],   moveOne  [1],   N - 1, 1);
	        auto moveThree  = increment(moveTwo  [0],   moveTwo  [1],   N - 1, 1);
	        auto moveFour   = increment(moveThree[0],   moveThree[1],   N - 1, 1);
	        auto moveFive   = increment(moveFour [0],   moveFour [1],   N - 1, 1);
	        auto moveSix    = increment(moveFive [0],   moveFive [1],   N - 1, 1);
	        
	        moves.push( { moveOne   [0], moveOne    [1], m+1, i, j });
	        moves.push( { moveTwo   [0], moveTwo    [1], m+1, i, j });
	        moves.push( { moveThree [0], moveThree  [1], m+1, i, j });
	        moves.push( { moveFour  [0], moveFour   [1], m+1, i, j });
	        moves.push( { moveFive  [0], moveFive   [1], m+1, i, j });
	        moves.push( { moveSix   [0], moveSix    [1], m+1, i, j });
	    }
	    else
	    {
	        auto nextSpace = findSpace(N, board[i][j]);
	        
			int lastI = curMove[3];
			int lastJ = curMove[4];

	        moves.push( { nextSpace[0], nextSpace[1], board[lastI][lastJ] == -1 ? m : m + 1, i, j });
	    }
	}
	
	return -1;
}

std::vector<int> SnakesAndLadders::increment(int i, int j, int N, int count)
{
	while (count > 0)
	{
		if ((N - i) % 2 == 0 && j < N)	++j; else
		if ((N - i) % 2 != 0 && j > 0)	--j;
		else							--i;

		--count;
	}

	return { i, j };
}

std::vector<int> SnakesAndLadders::findSpace(int N, int num)
{
	int row		= (num - 1) / N;
	int column	= row == 0 ? num - 1 : (num - 1) % (row * N);

	if ((N-row) % 2 != 0) column = N - column - 1;

	return { N - row - 1, column };
}
