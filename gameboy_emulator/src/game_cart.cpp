#include <cartdef.h>

typedef struct cart_desc
{
    char filename[1024];
    u32 rom_size;
    u8 *rom_data;

};

//No licensed cartridge makes use of game carttridge headers. The exact behavior is unknown.
// char buffers syntax remain the same from C to c++
// better to map each index to the bytes defined in the hardware?
static const char* rom_type[] {
"ROM ONLY",
"MBC1",
"MBC1+RAM",
"MBC1+RAM+BATTERY",
"MBC2",
"MBC2+BATTERY",
"ROM+RAM 1",
"ROM+RAM+BATTERY 1",
"MMM01",
"MMM01+RAM",
"MMM01+RAM+BATTERY",
"MBC3+TIMER+BATTERY",
"MBC3+TIMER+RAM+BATTERY 2",
"MBC3",
"MBC3+RAM 2",
"MBC3+RAM+BATTERY 2",
"MBC5",
"MBC5+RAM",
"MBC5+RAM+BATTERY",
"MBC5+RUMBLE",
"MBC5+RUMBLE+RAM",
"MBC5+RUMBLE+RAM+BATTERY",
"MBC6",
"MBC7+SENSOR+RUMBLE+RAM+BATTERY",
"POCKET CAMERA",
"BANDAI TAMA5",
"HuC3",
"HuC1+RAM+BATTERY",
};
