#pragma once
#include <memory>
#include <vector>

#include "DataStructures/Tree/Tree.h"

namespace Amazon
{

using namespace DataStructures;

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
