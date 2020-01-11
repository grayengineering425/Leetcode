#include "Spiral.h"

using namespace Amazon;

Spiral::Spiral(int n)
	:	n(n)
{
}

std::vector<std::vector<int>> Spiral::generateMatrix()
{
	std::vector<std::vector<int>> spiral(n, std::vector<int>(n, 0));
	
	int startX = 0;
	int startY = 0;
	
	int maxWidth = n;
	
	int cur = 1;
	
	while (cur <= std::pow(n, 2))
	{
	    int i = startX;
	    int j = startY;
	    
	    while (j < startY + maxWidth)
	    {
	        spiral[i][j] = cur;
	        
	        cur++;
	        j++;
	    }
		j--;
		i++;
	    
	    while (i < startX + maxWidth)
	    {
	        spiral[i][j] = cur;
	        cur++;
	        i++;
	    }
		i--;
		j--;
	    
	    while (j > startY)
	    {
	        spiral[i][j] = cur;
	        cur++;
	        j--;
	    }
	    
	    while (i > startX)
	    {
	        spiral[i][j] = cur;
	        
	        cur++;
	        i--;
	    }
	    
	    startX      += 1;
	    startY      += 1;
	    maxWidth    -= 2;
	}
	
	return spiral;
}
