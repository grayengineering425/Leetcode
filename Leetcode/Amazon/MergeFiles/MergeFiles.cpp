#include "MergeFiles.h"

#include <queue>

using namespace Amazon;

MergeFiles::MergeFiles(std::vector<int>& files)
	:	files(files)
{
}

int MergeFiles::run()
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        
    for (const auto& file: files) pq.push(file);
    
    int totalCost = 0;
    
    while (pq.size() > 1)
    {
        int stick1 = pq.top();
        pq.pop();
        
        int stick2 = pq.top();
        pq.pop();
        
        int cost = stick1 + stick2;
        totalCost += cost;
        
        pq.push(cost);
    }
    
    return totalCost;
}
