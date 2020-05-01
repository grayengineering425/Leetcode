#pragma once

struct Node
{
	Node(int val);

	int		val;
	Node*	next;
	Node*	random;
};

namespace Amazon {
class CopyListRandomPointer {
public:
	CopyListRandomPointer();

	Node* copyRandomList(Node* head);

private:
	Node* insert(Node* head, int val,		Node* random);
	Node* insert(Node* head, Node* newNode, Node* random);
};

}