#include <bus.h>
#include <cartdef.h>





/*
    0x0000 - 0x00FF: Boot ROM
    0x0000 - 0x3FFF: Game ROM Bank 0
    0x4000 - 0x7FFF: Game ROM Bank N
    0x8000 - 0x97FF: Tile RAM
    0x9800 - 0x9FFF: Background Map
    0xA000 - 0xBFFF: Cartridge RAM
    0xC000 - 0xDFFF: Working RAM
    0xE000 - 0xFDFF: Echo RAM
    0xFE00 - 0xFE9F: OAM (Object Atribute Memory)
    0xFEA0 - 0xFEFF: Unused
    0xFF00 - 0xFF7F: I/O Registers
    0xFF80 - 0xFFFE: High RAM Area
    0xFFFF: Interrupt Enabled Register
*/

// case statements wouldnt be scalable for memory ranges, but there's an exentension for 
// gcc that allows ranges ex: case 0x00 ... 0x3FFF: {}





int u8 bus_read(u16 address) {
    if (address < 0x8000) {
        //ROM Data
        return cart_read(address);
    }

    NO_IMPL
}
