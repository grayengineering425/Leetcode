#include "Amazon/Amazon.h"

#include <iostream>
#include <string>

using namespace Amazon;

int main()
{
	std::vector<int> nums = { 20, 50, 40, 25, 30, 10 };

	PairWithSum p(nums);

	p.findPair(90);
	
	return 0;
}