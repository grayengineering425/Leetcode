#pragma once
#include <string>

namespace Amazon
{

class RearrangeKDistance
{
public:
	RearrangeKDistance(std::string& s);

	std::string rearrange(int k);

private:
	std::string S;
};

}