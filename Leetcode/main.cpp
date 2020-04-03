#include "Amazon/Amazon.h"
#include "General/General.h"
#include "Microsoft/Microsoft.h"
#include "Google/Google.h"

#include <iostream>
#include <string>
#include <vector>

using namespace Amazon;
using namespace General;
using namespace Microsoft;
using namespace Google;
using namespace DataStructures;

int main()
{
	std::vector<int> nums	= { 1, 4, 3, 2, 5 };
	int k					= 4;

	LargestSubarrayLengthK l;

	for (const auto& n: l.getLargestByStart(nums, k)) std::cout << n << " ";

	std::cout << std::endl;
}