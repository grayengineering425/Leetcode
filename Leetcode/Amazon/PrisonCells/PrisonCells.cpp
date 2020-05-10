#include "PrisonCells.h"

using namespace Amazon;

PrisonCells::PrisonCells() = default;

std::vector<int> PrisonCells::prisonAfterNDays(std::vector<int>& cells, int N)
{
	N = (N - 1) % 14 + 1;
	
	for (int i=0; i<N; ++i)
	{
	    std::vector<int> newCells(cells.size(), 0);
	    
	    for (int j=1; j<cells.size() - 1; ++j)
	    {
	        if (cells[j-1] == 1 && cells[j+1] == 1) newCells[j] = 1; else
	        if (cells[j-1] == 0 && cells[j+1] == 0) newCells[j] = 1;
	    }
	    
	    cells = newCells;
	}
	
	return cells;
}
