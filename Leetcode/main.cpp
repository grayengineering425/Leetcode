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
	std::vector<int> loads ={ 1, 1, 1, 1, 1, 1 };

	LoadBalancer l;

	if (l.balanceLoad(loads))	std::cout << "True\n";
	else						std::cout << "False\n";
}