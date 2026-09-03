#include "io.h"

bool getShiftFlag(std::string_view label)
{
	std::cout << label << "(y/n): ";
	char input{};
	std::cin >> input;

	return input == 'y' || input == 'Y';
}

void printShiftFlag(std::string_view label, bool status)
{
	std::cout << std::boolalpha;
	std::cout << label << ": " << status << '\n';
}