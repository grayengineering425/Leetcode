#include "Amazon/Zombies/Zombies.h"
#include "Amazon/SearchSuggestion/Suggestion.h"
#include "Amazon/Cities/Cities.h"
#include "Amazon/TwoSum/TwoSum.h"
#include "Amazon/MaxAverageSubtree/MaxAverageSubtree.h"

#include <iostream>

using namespace Amazon;

int main()
{
	std::shared_ptr<TreeNode> t5 = std::make_shared<TreeNode>(5);
	std::shared_ptr<TreeNode> t6 = std::make_shared<TreeNode>(6);
	std::shared_ptr<TreeNode> t1 = std::make_shared<TreeNode>(1);

	t5->left = t6;
	t5->right= t1;

	MaxAverageSubtree m(t5);

	std::cout << m.getMaximumAverage() << std::endl;

	return 0;
}