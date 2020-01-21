#include "GenerateParentheses.h"

#include <stack>

using namespace Amazon;

GenerateParentheses::GenerateParentheses()
{
}

std::vector<std::string> GenerateParentheses::generate(int n)
{
	helper(n, n, "");

	return ans;
}

void GenerateParentheses::helper(int numOpen, int numClose, std::string current)
{
	if (numOpen == 0 && numClose == 0 && isValid(current)) ans.push_back(current);

    if (numClose > 0) helper(numOpen  , numClose-1, current + ")");
    if (numOpen  > 0) helper(numOpen-1, numClose  , current + "(");
}

bool GenerateParentheses::isValid(std::string & p)
{
	std::stack<char> s;
	
	for (size_t i=0; i<p.size(); ++i)
	{
	    if (p[i] == '(') s.push(p[i]);
	    else
	    {
	        if (s.empty()) return false;
	        s.pop();
	    }
	}
	return s.empty() ? true : false;
}
