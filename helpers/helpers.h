#ifndef HELPERS_H
#define HELPERS_H

#include <cstdint>

std::uint8_t setFlags(std::uint8_t prev, std::uint8_t mask);
std::uint8_t resetFlags(std::uint8_t prev, std::uint8_t mask);
std::uint8_t toggleFlags(std::uint8_t prev, std::uint8_t mask);
bool testFlags(std::uint8_t prev, std::uint8_t mask);

#endif
