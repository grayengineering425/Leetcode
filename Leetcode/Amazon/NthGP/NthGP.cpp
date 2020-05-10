#include "NthGP.h"

#include <sstream>
#include <iomanip>

using namespace Amazon;

NthGP::NthGP() = default;

char* NthGP::nthTerm(double input1, double input2, int input3)
{
	double ratio	 = input2 / input1;
	double firstTerm = input1/ratio;

	double nth		 = firstTerm * std::pow(ratio, input3 - 1); 

	std::stringstream ss;

	ss << nth << std::setprecision(3);

	//char charray[200];
	//sprintf(charray, "%.3f", num);
	//char* c = &charray[0];

	return (char*)ss.str().c_str();
}
