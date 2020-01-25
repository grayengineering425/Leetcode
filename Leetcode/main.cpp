#include "Amazon/Amazon.h"

#include <iostream>
#include <string>

using namespace Amazon;

int main()
{
	std::string s = "aaadbbcc";

	RearrangeKDistance r(s);

	std::cout << r.rearrange(2) << std::endl;
	
	return 0;
}