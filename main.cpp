#include "io/io.h"
#include <iostream>
#include <bitset>
#include <string_view>

int main()
{
	std::bitset<4> shiftFlags{};
	constexpr std::bitset<4> workedOvertime{ 1 << 0 };
	constexpr std::bitset<4> hitQuota{ 1 << 1 };
	constexpr std::bitset<4> supervisorRequired{ 1 << 2 };
	constexpr std::bitset<4> payrollReview{ 1 << 3 };

	std::cout << shiftFlags << '\n';
	std::cout << workedOvertime << '\n';
	std::cout << hitQuota << '\n';
	std::cout << supervisorRequired << '\n';
	std::cout << payrollReview << '\n';

	return EXIT_SUCCESS;
}