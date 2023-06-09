#pragma once

#include <definitions.h>

/*
0100-0103 — Entry point
0104-0133 — Nintendo logo
0134-0143 — Title
013F-0142 — Manufacturer code
// skip GCB specific code 0143 — CGB flag
0144-0145 — New licensee code
0146 — SGB flag
0147 — Cartridge type
0148 — ROM size
0149 — RAM size
014A — Destination code
014B — Old licensee code
014C — Mask ROM version number
014D — Header checksum
014E-014F — Global checksum*/


typedef struct
{
    u8 entry[4];
    u8 logo[48];
    char title[16];

    u16 new_lic_code;
    u8 sgb_flag;
    u8 cart_type;
    u8 rom_size;
    u8 ram_size; 
    u8 dest_code;
    u16 old_lic_code;
    u8 ver_num;
    u8 header_checksum;
    u16 global_checksum; 
} rom_header;

enum class RomType {
    ROM_ONLY,
    MBC1,
    MBC1_RAM,
    MBC1_RAM_BATTERY,
    MBC2,
    MBC2_BATTERY,
    ROM_RAM1,
    ROM_RAM_BATTERY1,
    MMM01,
    MMM01_RAM,
    MMM01_RAM_BATTERY,
    MBC3_TIMER_BATTERY,
    MBC3_TIMER_RAM_BATTERY2,
    MBC3,
    MBC3_RAM2,
    MBC3_RAM_BATTERY2,
    MBC5,
    MBC5_RAM,
    MBC5_RAM_BATTERY,
    MBC5_RUMBLE,
    MBC5_RUMBLE_RAM,
    MBC5_RUMBLE_RAM_BATTERY,
    MBC6,
    MBC7_SENSOR_RUMBLE_RAM_BATTERY,
    POCKET_CAMERA,
    BANDAI_TAMA5,
    HuC3,
    HuC1_RAM_BATTERY,
};

/* ROM sizes
32 KiB	2 (no banking)
$01	64 KiB	4
$02	128 KiB	8
$03	256 KiB	16
$04	512 KiB	32
$05	1 MiB	64
$06	2 MiB	128
$07	4 MiB	256
$08	8 MiB	512
$52	1.1 MiB	72 3
$53	1.2 MiB	80 3
$54	1.5 MiB	
*/

// in cartinfo.cc open ROM read rom data from space in memory defined in the memory map, get rom size from position and call 
// malloc() on return value
enum class RomSize {
    KB32,
    KB64,
    KB128,
    KB256,
    KB512,
    MiB1,
};

// global_checksum - (big-endian 16 bit) checksum is computed as the sum of all the bytes of the cartridge ROM
// header_checksum - 8-bit checksum computed from the cartridge header bytes $0134–014C

//extern: static or thread storage duration and external linkage. 
//extern auto rom_type(u8 type) -> RomType;

bool cart_load(char *cart);

// define cart_read/cart_write in cartinfo.cpp
u8 cart_read(u16 address);
void cart_write(u16 address, u8 value);

