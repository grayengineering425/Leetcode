#include "TimeBasedStore.h"

#include <algorithm>

using namespace General;

TimeBasedStore::TimeBasedStore()
{
}

void TimeBasedStore::set(std::string key, std::string value, int timestamp)
{
    valueMap[key].push_back(std::make_pair(value, timestamp));
}

std::string TimeBasedStore::get(std::string key, int timestamp)
{
    if (valueMap.find(key) == valueMap.end()) return "";
    
    return binarySearch(timestamp, valueMap[key], 0, valueMap[key].size() - 1);
}

std::string TimeBasedStore::binarySearch(int timestamp, std::vector<std::pair<std::string, int>>& values, int l, int r)
{
	while (l <= r)
	{
	    int mid = (l + r) / 2;
	    
	    if (values[mid].second <= timestamp)
	    {
	        if (mid+1 >= static_cast<int>(values.size()) || values[mid+1].second > timestamp)	return values[mid].first;
	        else																				l = mid + 1;
	    }
	    else r = mid - 1;
	}
	
	return "";
}