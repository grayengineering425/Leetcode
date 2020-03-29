#include "MaxBinaryDifference.h"

#include <algorithm>

using namespace Google;

struct BinaryTrieNode
{
	BinaryTrieNode()
		:	zero		(nullptr)
		,	one			(nullptr)
		,	maxTailZero	(0)
		,	maxTailOne	(0)
	{
	}

	BinaryTrieNode* zero;
	BinaryTrieNode* one;

	int maxTailZero;
	int maxTailOne;
};

void insert(BinaryTrieNode* root, const std::string& number, int index, int& maxDistance)
{
	if (index == number.size()) return;

	char cur = number[index];

	if (cur == '0')
	{
		if (root->one) maxDistance = std::max(maxDistance, root->maxTailOne + static_cast<int>(number.size()) - index);

		root->maxTailZero = std::max(root->maxTailZero, static_cast<int>(number.size()) - index);

		if (!root->zero) root->zero = new BinaryTrieNode();

		insert(root->zero, number, index+1, maxDistance);
	}
	else
	{
		if (root->zero) maxDistance = std::max(maxDistance, root->maxTailZero + static_cast<int>(number.size()) - index);

		root->maxTailOne = std::max(root->maxTailOne, static_cast<int>(number.size()) - index);

		if (!root->one) root->one = new BinaryTrieNode();

		insert(root->one, number, index+1, maxDistance);
	}
}


MaxBinaryDifference::MaxBinaryDifference() = default;

int MaxBinaryDifference::maxDistance(std::vector<std::string>& numbers)
{
	BinaryTrieNode* root = new BinaryTrieNode();

	int maxDistance = 0;

	for (const auto& number: numbers) insert(root, number, 0, maxDistance);

	return maxDistance;
}
