# Shift Status Flags

A small C++ console utility that packs several yes/no facts about a work
shift — overtime, quota, supervisor sign-off, payroll review — into a
single unsigned integer using bit flags, then demonstrates setting,
testing, clearing, and toggling individual flags by hand with the bitwise
operators.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter O: bit flags, bit masks, and the bitwise operators (`&`, `|`, `^`,
`~`, `<<`), plus `std::bitset` for display. Earlier fundamentals (multi-file
structure, `const`/`constexpr`, `std::string_view`) are used as supporting
scaffolding, not the focus.

## What it does

- Prompts for four yes/no shift conditions
- Packs each answer into its own bit of a `std::uint8_t`, using named
  bit-position constants and OR to set flags
- Prints the packed value in binary via `std::bitset<4>` for visual
  confirmation
- Reads each flag back independently with AND-based testing
- Demonstrates clearing a flag with AND-and-complement (`~`), and toggling
  a flag with XOR — showing the two are not interchangeable

## Project structure

```
main.cpp                // program entry point, orchestrates the flow
io/
  io.h                  // reading yes/no answers, printing flag status
  io.cpp           
helpers/                // setFlags, resetFlags, toggleFlags, testFlags
  helpers.h
  helpers.cpp        
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp io/io.cpp helpers/helpers.cpp
```

Or open `Shift Status Flags.slnx` in Visual Studio.

## Running

```bash
./app
```

Example session:

```
Worked overtime(y/n): y
Hit quota(y/n): y
Required a supervisor sign-off(y/n): y
Was flagged for payroll review(y/n): y
1111
Worked overtime: true
Hit quota: true
Required a supervisor sign-off: true
Was flagged for payroll review: true
[[ADMIN]]: Sign off completed.
false
[[ADMIN]]: Payroll review toggled.
false
```

## Notes

The packed value is stored and operated on as a plain `std::uint8_t`
throughout; `std::bitset` is used only at the print site for a readable
binary view, not for the packing/masking logic itself, which is
implemented by hand with `<<`, `|`, `&`, `~`, and `^` as a deliberate
exercise. Bit positions are named constants rather than bare shift
literals, both for readability and to make it harder for two flags to
accidentally collide on the same bit.