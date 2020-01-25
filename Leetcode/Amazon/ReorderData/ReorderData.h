#pragma once
#include <vector>

namespace Amazon
{

class ReorderData
{
public:
	ReorderData(std::vector<std::string>& logs);

	std::vector<std::string> reorder();

private:
	std::vector<std::string> logs;
};

}