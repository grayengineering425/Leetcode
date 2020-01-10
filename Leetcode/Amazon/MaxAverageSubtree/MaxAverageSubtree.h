#pragma once
#include <memory>
#include <vector>

namespace Amazon
{

struct TreeNode
{
	TreeNode(int val)
		:	val		(val)
		,	left	(nullptr)
		,	right	(nullptr)
	{
	}

	int							val;
	std::shared_ptr<TreeNode>	left;
	std::shared_ptr<TreeNode>	right;
};

class MaxAverageSubtree
{
public:
	explicit MaxAverageSubtree(std::shared_ptr<TreeNode>& root);

	double getMaximumAverage();

private:
	std::vector<double> getMaximumAverageHelper(std::shared_ptr<TreeNode>& root);

private:
	std::shared_ptr<TreeNode>	root;
	double						max;
};

}
