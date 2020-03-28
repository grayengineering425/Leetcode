//#include "Amazon/Amazon.h"
#include "General/General.h"
#include "Microsoft/Microsoft.h"
#include "Google/Google.h"
#include "DataStructures/Tree/Tree.h"

#include <iostream>
#include <string>
#include <vector>

using namespace General;
using namespace Microsoft;
using namespace Google;
using namespace DataStructures;

//class Solution {
//public:
//	int maxLevelSum(TreeNode* root)
//	{
//		if (!root) return 0;
//
//		int max = INT_MIN;
//		int maxLevel = 0;
//
//		std::queue<TreeNode*>   qNode;
//		std::queue<int>         qLevl;
//
//		qNode.push(root);
//		qLevl.push(1);
//
//		int lastLevel = 1;
//		int curSum = 0;
//
//		while (!qNode.empty())
//		{
//			auto curNode = qNode.front();
//			auto curLevl = qLevl.front();
//
//			qNode.pop();
//			qLevl.pop();
//
//			if (curLevl != lastLevel) { maxLevel = curSum > max ? lastLevel : maxLevel; max = std::max(max, curSum); curSum = 0; lastLevel = curLevl; }
//
//			curSum += curNode->val;
//
//			std::cout << curLevl << " " << curSum << "\n";
//
//			if (curNode->left) { qNode.push(curNode->left); qLevl.push(curLevl + 1); }
//			if (curNode->right) { qNode.push(curNode->right); qLevl.push(curLevl + 1); }
//		}
//
//		return maxLevel;
//	}
//};

int main()
{
	std::vector<int> A = { 5,1,3,4,2 };

	OddEven o;

	std::cout << o.oddEvenJumps(A) << "\n";

	return 0;
}