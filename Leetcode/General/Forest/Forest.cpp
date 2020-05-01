#include "Forest.h"
#include "DataStructures/Tree/Tree.h"

#include <queue>
#include <unordered_map>

using namespace Leetcode;

Forest::Forest() = default;

std::vector<std::shared_ptr<TreeNode>> Forest::delNodes(std::shared_ptr<TreeNode>& root, std::vector<int>& to_delete)
{
	if (!root) return {};

	std::vector<std::shared_ptr<TreeNode>> roots;
	
	std::unordered_map<int, bool> del;
	
	for (const auto& d: to_delete) del[d] = true;
	
	std::queue<std::shared_ptr<TreeNode>> qp;
	std::queue<std::shared_ptr<TreeNode>> q;

	q .push(root);
	qp.push(nullptr);
	
	if (del.find(root->val) == del.end()) roots.push_back(root);
	
	while (!q.empty() && !qp.empty())
	{
	    auto cur	= q.front();
		auto curP	= qp.front();
	    
		q .pop();
	    qp.pop();

	    if (cur->left ){ qp.push(cur); q.push(cur->left ); }
	    if (cur->right){ qp.push(cur); q.push(cur->right); }
	    
	    if (del.find(cur->val) != del.end())
	    {
	        if (cur->left && del.find(cur->left ->val) == del.end()) roots.push_back(cur->left );
	        if (cur->right&& del.find(cur->right->val) == del.end()) roots.push_back(cur->right);
	        
	        if (curP)
			{
				if (curP->left  && curP->left  == cur) curP->left  = nullptr; else
				if (curP->right && curP->right == cur) curP->right = nullptr;
			}
	    }
	}
	return roots;
}
