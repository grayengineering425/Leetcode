#pragma once
#include <memory>

namespace DataStructures { struct TreeNode; }

namespace Amazon
{

using namespace DataStructures;

class IsSubtree
{
public:
	IsSubtree(std::shared_ptr<TreeNode>& root1, std::shared_ptr<TreeNode>& root2);

	bool subtree();

private:
	bool subtree(std::shared_ptr<TreeNode>& root1, std::shared_ptr<TreeNode>& root2);
	bool compare(std::shared_ptr<TreeNode>& root1, std::shared_ptr<TreeNode>& root2);

private:
	std::shared_ptr<TreeNode> root1;
	std::shared_ptr<TreeNode> root2;
};

}