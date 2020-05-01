#pragma once
#include <vector>
#include <memory>

namespace DataStructures { struct TreeNode; }

namespace Leetcode
{

using namespace DataStructures;

//https://leetcode.com/problems/delete-nodes-and-return-forest/

class Forest
{
public:
	Forest();

	std::vector<std::shared_ptr<TreeNode>> delNodes(std::shared_ptr<TreeNode>& root, std::vector<int>& to_delete);
};

}