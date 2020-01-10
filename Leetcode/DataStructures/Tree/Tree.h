#pragma once
#include <memory>

namespace DataStructures
{

struct TreeNode
{
	TreeNode(int val);

	int							val;
	std::shared_ptr<TreeNode>	left;
	std::shared_ptr<TreeNode>	right;
};

}