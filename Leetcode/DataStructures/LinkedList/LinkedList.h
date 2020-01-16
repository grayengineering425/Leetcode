#pragma once
#include <memory>

namespace DataStructures
{

struct ListNode
{
	ListNode(int val);

	int							val;
	std::shared_ptr<ListNode>	next;
};

class LinkedList
{
public:
	static std::shared_ptr<ListNode> insert(std::shared_ptr<ListNode>& root, int val);
};

}