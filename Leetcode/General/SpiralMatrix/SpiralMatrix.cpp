#include "SpiralMatrix.h"

using namespace General;

SprialMatrix::SprialMatrix() = default;

std::vector<int> SprialMatrix::spiralOrder(std::vector<std::vector<int>>& matrix)
{
	if (matrix.empty()) return {};
	
	std::vector<int> ans;
	
	int startX = 0;
	int startY = 0;
	
	int maxWidth = matrix[0].size()-1;
	int maxHeight= matrix	.size()-1;          
	    
	while (startX <= maxWidth && startY <= maxHeight)
	{
		int j = startX;
		int i = startY;
	
		while (j <= maxWidth ) ans.push_back(matrix[startY][j++]);
		++i;
	
		while (i <= maxHeight) ans.push_back(matrix[i++][maxWidth]);
	
		if (startY != maxHeight)
		{
			j = maxWidth-1;
	
			while (j >= startX) ans.push_back(matrix[maxHeight][j--]);
		}
		if (startX != maxWidth)
		{
			i = maxHeight-1;
			while (i > startY) ans.push_back(matrix[i--][startX]);
		}
	
		startX++;
		startY++;
	
		maxWidth --;
		maxHeight--;
	}
	
	return ans;
}
