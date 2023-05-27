#pragma once

#include <definitions.h>

struct romheader 
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
};

// global_checksum - (big-endian 16 bit) checksum is computed as the sum of all the bytes of the cartridge ROM
// header_checksum - 8-bit checksum computed from the cartridge header bytes $0134–014C
// skipping any headers specific to gbc/gba for now

#define bool cart_load(char *cart);

#define int u8 cart_read(u16 address);
#define void cart_write(u16 address, u8 value);


