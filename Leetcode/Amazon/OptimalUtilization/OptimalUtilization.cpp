#include "OptimalUtilization.h"

#include <algorithm>

using namespace Amazon;

OptimalUtilization::OptimalUtilization(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b)
	:	a		(a)
	,	b		(b)
	,	closest	(INT_MAX)
{
}

std::vector<std::vector<int>> OptimalUtilization::findOptimal(int target)
{
	if (a.empty() || b.empty()) return {};

	std::vector<std::vector<int>> ans;

	auto compare = [this](const std::vector<int>& lhs, const std::vector<int>& rhs)
	{
		return lhs[1] < rhs[1];
	};

	std::sort(b.begin(), b.end(), compare);

	for (int i=0; i<a.size(); ++i)
	{
		int search = target - a[i][1];

		binarySearch(b, ans, a[i][1], a[i][0], target, 0, b.size()-1);
	}

	return ans;
}

void OptimalUtilization::binarySearch(std::vector<std::vector<int>>& arr, std::vector<std::vector<int>>& ans, int partner, int partnerId, int target, int l, int r)
{
	if (l <= r)
	{
		int mid = (l + r) / 2;
		int num = arr[mid][1];

		if (num + partner <= target)
		{
			if (target - num - partner <= closest)
			{
				if (target - num - partner < closest)
				{
					ans.clear();
					closest = target - num - partner;
				}
				
				int searchL = mid;
				int searchR = mid + 1;

				while (searchL > -1			&& target - arr[searchL][1] - partner == closest) ans.push_back({ partnerId, arr[searchL--][0] });
				while (searchR < arr.size() && target - arr[searchR][1] - partner == closest) ans.push_back({ partnerId, arr[searchR++][0] });

				if (closest == 0) return;
			}
			binarySearch(arr, ans, partner, partnerId, target, mid+1, r);
		}
		else  binarySearch(arr, ans, partner, partnerId, target, l, mid-1);
	}
}
