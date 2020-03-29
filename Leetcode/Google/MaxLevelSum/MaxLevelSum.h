#pragma once
#include <memory>

namespace DataStructures { struct TreeNode; }

namespace Google
{
//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
class MaxLevelSum
{
public:
	MaxLevelSum();

	int maxLevelSum(std::shared_ptr<DataStructures::TreeNode>& root);
};

}
