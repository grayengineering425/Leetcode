#pragma once
#include <vector>

namespace Amazon
{

class MergeFiles
{
public:
	MergeFiles(std::vector<int>& files);

	int run();

private:
	std::vector<int> files;
};


}