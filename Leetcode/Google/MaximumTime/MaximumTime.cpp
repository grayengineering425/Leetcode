#include "MaximumTime.h"

using namespace Google;

MaximumTime::MaximumTime() = default;

std::string MaximumTime::getMaximum(std::string & time)
{
	if (time.size() < 5) return "";
	
	for (int i=0; i<time.size(); ++i)
	{
		if (time[i] == '?')
		{
			if (i == 0) time[i] = (time[1] <= '3' || time[1] == '?')	? '2' : '1';	else
			if (i == 1) time[i] =  time[0] == '2'						? '3' : '9';	else
			if (i == 3) time[i] = '5';													else
			if (i == 4) time[i] = '9';
		}
	}

	return time;
}
