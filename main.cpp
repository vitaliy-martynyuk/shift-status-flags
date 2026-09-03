#include "io/io.h"
#include "helpers/helpers.h"
#include <iostream>
#include <bitset>
#include <string_view>
#include <cstdint>

int main()
{
	std::uint8_t shiftFlags{ 0b0000 };
	constexpr std::uint8_t workedOvertime{ 1 << 0 };
	constexpr std::uint8_t hitQuota{ 1 << 1 };
	constexpr std::uint8_t supervisorRequired{ 1 << 2 };
	constexpr std::uint8_t payrollReview{ 1 << 3 };

	constexpr std::string_view workedOvertimeLabel{ "Worked overtime" };
	constexpr std::string_view hitQuotaLabel{ "Hit quota" };
	constexpr std::string_view supervisorRequiredLabel{ "Required a supervisor sign-off" };
	constexpr std::string_view payrollReviewLabel{ "Was flagged for payroll review" };

	if (getShiftFlag(workedOvertimeLabel))
		shiftFlags = setFlags(shiftFlags, workedOvertime);

	if (getShiftFlag(hitQuotaLabel))
		shiftFlags = setFlags(shiftFlags, hitQuota);

	if (getShiftFlag(supervisorRequiredLabel))
		shiftFlags = setFlags(shiftFlags, supervisorRequired);

	if (getShiftFlag(payrollReviewLabel))
		shiftFlags = setFlags(shiftFlags, payrollReview);

	std::cout << std::bitset<4>(shiftFlags) << '\n';

	printShiftFlag(workedOvertimeLabel, testFlags(shiftFlags, workedOvertime));
	printShiftFlag(hitQuotaLabel, testFlags(shiftFlags, hitQuota));
	printShiftFlag(supervisorRequiredLabel, testFlags(shiftFlags, supervisorRequired));
	printShiftFlag(payrollReviewLabel, testFlags(shiftFlags, payrollReview));

	return EXIT_SUCCESS;
}