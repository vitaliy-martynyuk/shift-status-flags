#ifndef IO_H
#define IO_H

#include <iostream>
#include <string_view>

bool getShiftFlag(std::string_view label);
void printShiftFlag(std::string_view label, bool status);

#endif
