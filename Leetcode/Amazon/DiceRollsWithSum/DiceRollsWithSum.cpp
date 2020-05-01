#include "DiceRollsWithSum.h"

using namespace Amazon;

DiceRollsWithSum::DiceRollsWithSum() = default;

int DiceRollsWithSum::numRollsToTarget(int d, int f, int target)
{
	if (d == 0 || f == 0 || target == 0) return 0;
	
	std::vector<std::vector<int>> dp(d, std::vector<int>(target, 0));
	
	for (int i=0; i<dp[0].size() && i < f; ++i) dp[0][i] = 1;
	
	for (int i=1; i<dp   .size(); ++i)
	for (int j=0; j<dp[i].size(); ++j)
	{
	    int face = 1;
	    
	    while (face < f+1 && j - face >= 0)
	    {
	        dp[i][j] = (dp[i][j] + dp[i-1][j-face]) % 1000000007;
	        
	        face++;
	    }
	}
	
	return dp[dp.size()-1][dp[0].size()-1];
}
