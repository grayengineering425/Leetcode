#include "MaxAverageSubtree.h"

#include <algorithm>

using namespace Amazon;

MaxAverageSubtree::MaxAverageSubtree(std::shared_ptr<TreeNode>& root)
	:	root(root)
	,	max	(-1000.0)
{
}

double MaxAverageSubtree::getMaximumAverage()
{
	auto cur = root;

	getMaximumAverageHelper(cur);

	return max;
}

std::vector<double> MaxAverageSubtree::getMaximumAverageHelper(std::shared_ptr<TreeNode>& cur)
{
	if (!cur)																return { 0.0,				0.0 };
	if (!cur->left && !cur->right){ max = std::max(max, (double)cur->val);	return { (double)cur->val,	1.0 }; }

	auto sumLeft	= getMaximumAverageHelper(cur->left);
	auto sumRight	= getMaximumAverageHelper(cur->right);

	double average = (sumLeft[0] + sumRight[0] + cur->val) / (sumLeft[1] + sumRight[1] + 1);

	max = std::max(max, average);

	return { sumLeft[0] + sumRight[0] + cur->val, sumLeft[1] + sumRight[1] + 1 };
}
