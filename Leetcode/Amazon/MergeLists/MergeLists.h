#pragma once
#include <memory>

namespace DataStructures { struct ListNode; }

namespace Amazon
{

using namespace DataStructures;

class MergeLists
{
public:
	MergeLists(std::shared_ptr<ListNode>& root1, std::shared_ptr<ListNode>& root2);

	ListNode* run();

private:
	std::shared_ptr<ListNode>& l1;
	std::shared_ptr<ListNode>& l2;
};

}