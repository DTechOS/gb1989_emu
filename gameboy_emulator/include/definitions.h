#pragma once

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <dos.h>


using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using s8 = std::int8_t;
using s16 = std::int16_t;


// macro for setting bits
#define BIT(a, n) ((a & (1 << n)) ? 1 : 0)

#define BIT_SET(a, n, on) { if (on) a |= (1 << n); else a &= ~(1 << n);}

#define BETWEEN(a, b, c) ((a >= b) && (a <= c))

void delay(u32);

#define NO_IMPL { std::cout << "NOT YET IMPLMENTED"; std::exit(EXIT_FAILURE); }


