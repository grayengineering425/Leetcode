#pragma once
#include <vector>

namespace Amazon
{

class KDistinctSubstrings
{
public:
	KDistinctSubstrings(std::string& s);

	int getSubstrings(int k);

private:
	int getSubstringsHelper(int k);

private:
	std::string s;
};

}