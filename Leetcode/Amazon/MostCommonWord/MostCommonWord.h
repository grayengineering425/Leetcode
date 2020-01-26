#pragma once
#include <vector>

namespace Amazon
{

class MostCommonWord
{
public:
	MostCommonWord(std::string paragraph, std::vector<std::string>& banned);

	std::string getMostCommon();

private:
	std::string					paragraph;
	std::vector<std::string>&	banned;
};

}