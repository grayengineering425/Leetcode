#pragma once
#include <string>

namespace Amazon
{

class Battleships
{
public:
	Battleships();

	std::string getInfo(int n, const std::string& s, const std::string& t);
};

}