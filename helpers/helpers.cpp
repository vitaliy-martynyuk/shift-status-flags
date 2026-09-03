#include "helpers.h"

std::uint8_t setFlags(std::uint8_t prev, std::uint8_t mask)
{
	return static_cast<std::uint8_t>(prev | mask);
}

std::uint8_t resetFlags(std::uint8_t prev, std::uint8_t mask)
{
	return static_cast<std::uint8_t>(prev & static_cast<std::uint8_t>(~mask));
}

std::uint8_t toggleFlags(std::uint8_t prev, std::uint8_t mask)
{
	return static_cast<std::uint8_t>(prev ^ mask);
}

bool testFlags(std::uint8_t prev, std::uint8_t mask)
{
	return static_cast<bool>(prev & mask);
}