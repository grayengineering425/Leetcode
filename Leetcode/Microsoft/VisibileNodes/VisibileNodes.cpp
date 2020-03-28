#include "VisibileNodes.h"
#include "DataStructures/Tree/Tree.h"

#include <algorithm>

using namespace Microsoft;

VisibleNodes::VisibleNodes()
{
}

int VisibleNodes::getNumberOfVisibleNodes(std::shared_ptr<DataStructures::TreeNode>& root)
{
	if (!root) return 0;

	int count	= 0;
	int max		= INT_MIN;

	dfs(root, count, max);

	return count;
}

void VisibleNodes::dfs(std::shared_ptr<DataStructures::TreeNode>& root, int & count, int max)
{
	if (!root) return;

	if (root->val > max) ++count;

	max = std::max(max, root->val);

	if (root->left ) dfs(root->left , count, max);
	if (root->right) dfs(root->right, count, max);
}
