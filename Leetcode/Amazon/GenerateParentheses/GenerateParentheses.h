#pragma once
#include <vector>

namespace Amazon
{

class GenerateParentheses
{
public:
	GenerateParentheses();

	std::vector<std::string> generate(int n);

private:
	void helper	(int numOpen, int numClose, std::string current);
	bool isValid(std::string& p);

private:
	std::vector<std::string> ans;
};


}