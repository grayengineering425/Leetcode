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
	PointOfLattice p;

	std::cout << p.getPoint(-1,3,3,1) << std::endl;
}