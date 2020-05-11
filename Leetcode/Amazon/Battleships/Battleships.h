#pragma once
#include <string>

namespace Amazon
{

class Battleships
{
public:
	Battleships();

	std::string getResult(std::string& S, std::string& T);
};

}