#pragma once
#include <sstream>
#include <iomanip>
#include <string>

// Helper Class creating some template formats for manipulating
// numbers for display etc...
class NumberFormatter
{

public:

// creates a string with two decimal places
template <typename T>
std::string convert_to_two_decimal_string(T num) {

	// create an output string stream
	std::ostringstream Convert;

	// do the string manipulation through the stream
	Convert << std::fixed << std::setprecision(2) << num;

	// get the string value
	return Convert.str();
}
};

