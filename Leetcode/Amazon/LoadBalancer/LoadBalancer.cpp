#include "LoadBalancer.h"

using namespace Amazon;

LoadBalancer::LoadBalancer() = default;

bool LoadBalancer::balanceLoad(std::vector<int>& A)
{
	int l = 1;
	int r = A.size()-2;

	int leftSum		= A[0];
	int rightSum	= A[A.size()-1];
	int middleSum	= 0;

	for (int i=l+1; i<r; ++i) middleSum += A[i];

	while (l < r)
	{
		if (leftSum == rightSum && rightSum == middleSum)
			return true;
		
		else if (leftSum < rightSum)
		{
			leftSum		+= A[l];
			middleSum	-= A[l+1];

			++l;
		}
		else
		{
			rightSum	+= A[r];
			middleSum	-= A[r-1];

			--r;
		}
	}

	return false;
}
