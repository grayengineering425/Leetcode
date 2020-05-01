#pragma once
#include <vector>

namespace Leetcode { namespace Google
{

//https://leetcode.com/discuss/interview-question/356520

class PartyChairs
{
public:
	PartyChairs(std::vector<int>& guestEntry, std::vector<int>& guestExit);

	int minChairs();

private:
	std::vector<int> guestEntry;
	std::vector<int> guestExit;
};

}}
