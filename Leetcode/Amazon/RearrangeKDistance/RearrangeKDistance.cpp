#include "RearrangeKDistance.h"

#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>

using namespace Amazon;

RearrangeKDistance::RearrangeKDistance(std::string & s)
	:	S(s)
{
}

std::string RearrangeKDistance::rearrange(int k)
{
	if (k < 2) return S;
	
	std::unordered_map<char, int> count;
	
	for (const auto& c: S) count[c]++;
	
	auto compare = [this](const std::tuple<char, int>& lhs, const std::tuple<char, int>& rhs)
	{
	    int countL = std::get<1>(lhs);
	    int countR = std::get<1>(rhs);
	    
	    if (countL == countR) return std::get<0>(lhs) < std::get<0>(rhs); 
	    
	    return countL < countR;
	};
	
	std::priority_queue<std::tuple<char, int>, std::vector<std::tuple<char, int>>, decltype(compare)> pq(compare);
	
	for (const auto& pair: count) pq.push(std::make_tuple(pair.first, pair.second));
	
	std::string ans = "";
	
	while (!pq.empty())
	{
	    std::vector<std::tuple<char, int>> cache;
	    
	    auto mostFrequent = pq.top();
	    pq.pop();
	    
	    char mostFrequentChar   = std::get<0>(mostFrequent);
	    int  mostFrequentCount  = std::get<1>(mostFrequent);
	    
	    ans += mostFrequentChar;
	    mostFrequentCount--;
	    
	    if (mostFrequentCount > 0) cache.push_back(std::make_tuple(mostFrequentChar, mostFrequentCount));
	    
	    if (pq.empty() && mostFrequentCount > 0) ans = "";
	    
	    else
	    {
	        int count = 1;
	        
	        while (count < k && !pq.empty())
	        {
	            auto nextMostFrequent = pq.top();
	            pq.pop();
	        
	            char nextMostFrequentChar   = std::get<0>(nextMostFrequent);
	            int  nextMostFrequentCount  = std::get<1>(nextMostFrequent);
	            
	            ans += nextMostFrequentChar;
	            
	            nextMostFrequentCount--;
	            
	            if (nextMostFrequentCount > 0) cache.push_back(std::make_tuple(nextMostFrequentChar, nextMostFrequentCount));
	            
	            count++;
	
	            if (pq.empty() && !cache.empty() && count < k) return "";
	        }
	        
	        for (const auto& freq: cache) pq.push(freq);
	    }
	}
	return ans;
}
