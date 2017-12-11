#pragma once
#include <sstream>
#include <iomanip>
#include <locale>

class NumberFormatter
{
public:
	NumberFormatter();
	~NumberFormatter();

	template <typename T>
	T convert_to_two_decimals(T num) {
		T = T * 100;
		int retr = std::static_cast<int>(T);
		T = std::static_cast<T>(retr);
		T = T / 100;
		return T;
	}

	template <typename T>
	std::string convert_to_two_decimal_string(T num) {
		std::ostringstream Convert;
		Convert << std::fixed << std::setprecision(2) << num;
		return Convert.str();
	}

};

