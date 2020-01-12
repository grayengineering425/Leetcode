#include "Search2D.h"

using namespace Amazon;

Search2D::Search2D(std::vector<std::vector<int>>& matrix)
	:	matrix(matrix)
{
}

bool Search2D::searchMatrix(int target)
{
	if (matrix.empty()) return false;
        
    int m = 0;
    int n = matrix[0].size()-1;
    
    while(m < (int)matrix.size() && n > -1)
    {
        if (matrix[m][n] > target)  n--;            else
        if (matrix[m][n] < target)  m++;
        else                        return true;
    }
    
	return false;
}
