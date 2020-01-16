#pragma once
#include <vector>

namespace Amazon
{

class TopBuzzwords
{
public:
	TopBuzzwords(std::vector<std::string>& toys, std::vector<std::string>& quotes);

	std::vector<std::string> topN(int n);

private:
	std::vector<std::string> toys;
	std::vector<std::string> quotes;
};

}