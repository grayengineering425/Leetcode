#include "LinkedList.h"

using namespace DataStructures;

ListNode::ListNode(int val)
	:	val	(val)
	,	next(nullptr)
{
}

std::shared_ptr<ListNode> LinkedList::insert(std::shared_ptr<ListNode>& root, int val)
{
	std::shared_ptr<ListNode> next = std::make_shared<ListNode>(val);

	if (!root)
	{
		root = next;
		return root;
	}

	std::shared_ptr<ListNode> cur = root;

	while (cur->next) cur = cur->next;

	cur->next = next;

	return root;
}
