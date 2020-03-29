#include "MaxLevelSum.h"
#include "DataStructures/Tree/Tree.h"

#include <queue>
#include <algorithm>

using namespace Google;
using namespace DataStructures;

MaxLevelSum::MaxLevelSum() = default;

int MaxLevelSum::maxLevelSum(std::shared_ptr<DataStructures::TreeNode>& root)
{
	if (!root) return 0;
	
	int max			= INT_MIN;
	int maxLevel	= 0;
	
	std::queue<std::shared_ptr<TreeNode>>   qNode;
	std::queue<int>							qLevl;
	
	qNode.push(root);
	qLevl.push(1);
	
	int lastLevel = 1;
	int curSum = 0;
	
	while (!qNode.empty())
	{
		auto curNode = qNode.front();
		auto curLevl = qLevl.front();
	
		qNode.pop();
		qLevl.pop();
	
		if (curLevl != lastLevel) { maxLevel = curSum > max ? lastLevel : maxLevel; max = std::max(max, curSum); curSum = 0; lastLevel = curLevl; }
	
		curSum += curNode->val;
	
		if (curNode->left ) { qNode.push(curNode->left ); qLevl.push(curLevl + 1); }
		if (curNode->right) { qNode.push(curNode->right); qLevl.push(curLevl + 1); }
	}
	
	return maxLevel;
}
