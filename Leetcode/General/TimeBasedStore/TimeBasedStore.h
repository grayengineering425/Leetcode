#pragma once
#include <vector>
#include <unordered_map>

namespace General
{

class TimeBasedStore
{
public:
	TimeBasedStore();

	void		set(std::string key, std::string value, int timestamp);
	std::string get(std::string key, int timestamp);

private:
	std::string binarySearch(int timestamp, std::vector<std::pair<std::string, int>>& values, int l, int r);

private:
	std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> valueMap;
};

}
