#pragma once
#include <vector>

namespace Amazon
{

class LoadBalancer
{
public:
	LoadBalancer();

	bool balanceLoad(std::vector<int>& A);
};

}