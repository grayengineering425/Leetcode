#pragma once
#include <memory>

namespace DataStructures { struct TreeNode; }

namespace Microsoft
{
//https://leetcode.com/discuss/interview-question/546703/microsoft-oa-2020-count-visible-nodes-in-binary-tree
class VisibleNodes
{
public:
	VisibleNodes();

	int getNumberOfVisibleNodes(std::shared_ptr<DataStructures::TreeNode>& root);

private:
	void dfs(std::shared_ptr<DataStructures::TreeNode>& root, int &count, int max);
};

}
