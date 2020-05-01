#include "IsSubtree.h"
#include "DataStructures/Tree/Tree.h"

using namespace Amazon;

IsSubtree::IsSubtree(std::shared_ptr<TreeNode>& root1, std::shared_ptr<TreeNode>& root2)
	:	root1(root1)
	,	root2(root2)
{
}

bool IsSubtree::subtree()
{
	return subtree(root1, root2);
}

bool IsSubtree::subtree(std::shared_ptr<TreeNode>& s, std::shared_ptr<TreeNode>& t)
{
	if (!s || !t) return false;

	if (s->val == t->val)
	{
		bool b = compare(s, t);

		if (b) return true;
	}

	bool l = subtree(s->left,	t);
	bool r = subtree(s->right,	t);

	return l | r;
}

bool IsSubtree::compare(std::shared_ptr<TreeNode>& s, std::shared_ptr<TreeNode>& t)
{
	if (!s && !t) return true;
	
	if ((!s && t) || (s && !t) || (s->val != t->val)) return false;
	
	bool l = compare(s->left, t->left);
	bool r = compare(s->right, t->right);
	
	return l & r;
}
