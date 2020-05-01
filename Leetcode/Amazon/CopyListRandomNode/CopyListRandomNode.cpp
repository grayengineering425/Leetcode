#include "CopyListRandomNode.h"

#include <unordered_map>

using namespace Amazon;

Node::Node(int val)
	:	val		(val)
	,	next	(nullptr)
	,	random	(nullptr)
{
}

CopyListRandomPointer::CopyListRandomPointer() = default;

Node* CopyListRandomPointer::copyRandomList(Node * head)
{
	Node* copy = nullptr;
	std::unordered_map<Node*, Node*> nodes;
	
	Node* cur = head;
	
	while (cur)
	{
		if (cur->random) nodes[cur->random] = new Node(cur->random->val);
	
		cur = cur->next;
	}
	
	cur = head;
	
	while (cur)
	{
		if (nodes[cur]) copy = insert(copy, nodes[cur], nodes[cur->random]);
		else            copy = insert(copy, cur->val,	nodes[cur->random]);
	
		cur = cur->next;
	}
	
	return copy;
}

Node* CopyListRandomPointer::insert(Node * head, int val, Node * random)
{
	Node *newNode = new Node(val);
	newNode->random = random;
	
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node* cur = head;
		while (cur->next) cur = cur->next;
		cur->next = newNode;
	}
	
	return head;
}

Node* CopyListRandomPointer::insert(Node * head, Node * newNode, Node * random)
{
	newNode->random = random;
	
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node* cur = head;
		while (cur->next) cur = cur->next;
		cur->next = newNode;
	}
	return head;
}
