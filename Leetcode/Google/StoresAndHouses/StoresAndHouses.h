#pragma once
#include <vector>

namespace Leetcode { namespace Google
{

//https://leetcode.com/discuss/interview-question/350248/Google-or-Summer-Intern-OA-2019-or-Stores-and-Houses

class StoresAndHouses
{
public:
	StoresAndHouses();

	std::vector<int> getClosestStores(std::vector<int>& houses, std::vector<int>& stores);

private:
	int binarySearch(std::vector<int>& stores, int location);
};
}}
