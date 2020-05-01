#pragma once
#include <vector>

namespace Amazon
{

class OptimalUtilization
{
public:
	OptimalUtilization(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b);

	std::vector<std::vector<int>> findOptimal(int target);

private:
	void binarySearch(std::vector<std::vector<int>>& arr, std::vector<std::vector<int>>& ans, int partner, int partnerId, int target, int l, int r);

private:
	std::vector<std::vector<int>> a;
	std::vector<std::vector<int>> b;

	int closest;
};

}