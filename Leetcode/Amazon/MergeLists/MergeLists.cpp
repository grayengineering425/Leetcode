#include "MergeLists.h"
#include "DataStructures/LinkedList/LinkedList.h"

using namespace Amazon;

MergeLists::MergeLists(std::shared_ptr<ListNode>& root1, std::shared_ptr<ListNode>& root2)
	:	l1(root2)
	,	l2(root2)
{
}

ListNode * MergeLists::run()
{
	std::shared_ptr<ListNode> sorted = nullptr;
	
	while (l1 && l2)
	{
	    if (l1->val < l2->val){ sorted = LinkedList::insert(sorted, l1->val); l1 = l1->next; }
	    else{                   sorted = LinkedList::insert(sorted, l2->val); l2 = l2->next; }
	}
	
	while (l1)
	{
	    sorted  = LinkedList::insert(sorted, l1->val);
	    l1      = l1->next;
	}
	while (l2)
	{
	    sorted  = LinkedList::insert(sorted, l2->val);
	    l2      = l2->next;
	}
	
	return sorted.get();
}
