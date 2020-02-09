#pragma once
#include <vector>

namespace Amazon
{

class ParitionLabels
{
public:
	ParitionLabels(std::string& S);

	std::vector<int> partitionLabels();

private:
	std::string S;
};

}