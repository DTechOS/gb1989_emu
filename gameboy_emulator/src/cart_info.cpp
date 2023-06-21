#include <cartinfo.h>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

auto rom_type(u8 type) -> RomType {
    switch (type) {
        case 0x00:
        case 0x08:
        case 0x09:
            return RomType::ROM_ONLY;

        case 0x01: 
        case 0x02:
        case 0x03:
            return RomType::MBC1;
        
        case 0x05:
        case 0x06:
            return RomType::MBC2;

        case 0x0B:
        case 0x0C:
        case 0x0D:
            return RomType::MMM01;

        case 0x0F:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            return RomType::MBC3;
        
        case 0x19: 
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1C:
            return RomType::MBC5;

        case 0x20:
            return RomType::MBC6;

        case 0x22:
            return RomType::MBC7;

        case 0xFC:
            return RomType::POCKET_CAMERA; //probably could put 0xFC and 0xFD in "Unused"

        case 0xFD:
            return RomType::BANDAI_TAMA5;

        case 0xFE:
            return RomType::HuC3;

        case 0xFF:
            return RomType::HuC1_RAM_BATTERY;
        } 
};


/* ROM TYPES:
$00	ROM ONLY
$01	MBC1
$02	MBC1+RAM
$03	MBC1+RAM+BATTERY
$05	MBC2
$06	MBC2+BATTERY
$08	ROM+RAM 1
$09	ROM+RAM+BATTERY 1
$0B	MMM01
$0C	MMM01+RAM
$0D	MMM01+RAM+BATTERY
$0F	MBC3+TIMER+BATTERY
$10	MBC3+TIMER+RAM+BATTERY 2
$11	MBC3
$12	MBC3+RAM 2
$13	MBC3+RAM+BATTERY 2
$19	MBC5
$1A	MBC5+RAM
$1B	MBC5+RAM+BATTERY
$1C	MBC5+RUMBLE
$1D	MBC5+RUMBLE+RAM
$1E	MBC5+RUMBLE+RAM+BATTERY
$20	MBC6
$22	MBC7+SENSOR+RUMBLE+RAM+BATTERY
$FC	POCKET CAMERA
$FD	BANDAI TAMA5
$FE	HuC3
$FF	HuC1+RAM+BATTERY
*/


// <map>,<string> used to map hex key to publisher
// think this fixes the memory leak
const std::unordered_map<u8, const char*> LIC_CODE {
     {0x01, "Nintendo R&D1"},
     {0x08, "Capcom"},
     {0x13, "Electronic Arts"},
     {0x18, "Hudson Soft"},
     {0x19, "b-ai"},
     {0x20, "kss"},
     {0x22, "pow"},
     {0x24, "PCM Complete"},
     {0x25, "san-x"},
     {0x28, "Kemco Japan"},
     {0x29, "seta"},
     {0x30, "Viacom"},
     {0x31, "Nintendo"},
     {0x32, "Bandai"},
     {0x33, "Ocean/Acclaim"},
     {0x34, "Konami"},
     {0x35, "Hector"},
     {0x37, "Taito"},
     {0x38, "Hudson"},
     {0x39, "Banpresto"},
     {0x41, "Ubi Soft"},
     {0x42, "Atlus"},
     {0x44, "Malibu"},
     {0x46, "angel"},
     {0x47, "Bullet-Proof"},
     {0x49, "irem"},
     {0x50, "Absolute"},
     {0x51, "Acclaim"},
     {0x52, "Activision"},
     {0x53, "American sammy"},
     {0x54, "Konami"},
     {0x55, "Hi tech entertainment"},
     {0x56, "LJN"},
     {0x57, "Matchbox"},
     {0x58, "Mattel"},
     {0x59, "Milton Bradley"},
     {0x60, "Titus"},
     {0x61, "Virgin"},
     {0x64, "LucasArts"},
     {0x67, "Ocean"},
     {0x69, "Electronic Arts"},
     {0x70, "Infogrames"},
     {0x71, "Interplay"},
     {0x72, "Broderbund"},
     {0x73, "sculptured"},
     {0x75, "sci"},
     {0x78, "THQ"},
     {0x79, "Accolade"},
     {0x80, "misawa"},
     {0x83, "lozc"},
     {0x86, "Tokuma Shoten Intermedia"},
     {0x87, "Tsukuda Original"},
     {0x91, "Chunsoft"},
     {0x92, "Video system"},
     {0x93, "Ocean/Acclaim"},
     {0x95, "Varie"},
     {0x96, "Yonezawa/s’pal"},
     {0x97, "Kaneko"},
     {0x99, "Pack in soft"},
     {0xA4, "Konami"}
    };
    
std::map<int, std::string> new_lic_code[] {
     std::map <int,  std::string>{{0x00, "None"}},
     std::map <int, std::string>{{0x01, "Nintendo R&D1"}},
     std::map <int, std::string>{{0x08, "Capcom"}},
     std::map <int, std::string>{{0x13, "Electronic Arts"}},
     std::map <int, std::string>{{0x18, "Hudson Soft"}},
     std::map <int, std::string>{{0x19, "b-ai"}},
     std::map <int, std::string>{{0x20, "kss"}},
     std::map <int, std::string>{{0x22, "pow"}},
     std::map <int, std::string>{{0x24, "PCM Complete"}},
     std::map <int, std::string>{{0x25, "san-x"}},
     std::map <int, std::string>{{0x28, "Kemco Japan"}},
     std::map <int, std::string>{{0x29, "seta"}},
     std::map <int, std::string>{{0x30, "Viacom"}},
     std::map <int, std::string>{{0x31, "Nintendo"}},
     std::map <int, std::string>{{0x32, "Bandai"}},
     std::map <int, std::string>{{0x33, "Ocean/Acclaim"}},
     std::map <int, std::string>{{0x34, "Konami"}},
     std::map <int, std::string>{{0x35, "Hector"}},
     std::map <int, std::string>{{0x37, "Taito"}},
     std::map <int, std::string>{{0x38, "Hudson"}},
     std::map <int, std::string>{{0x39, "Banpresto"}},
     std::map <int, std::string>{{0x41, "Ubi Soft"}},
     std::map <int, std::string>{{0x42, "Atlus"}},
     std::map <int, std::string>{{0x44, "Malibu"}},
     std::map <int, std::string>{{0x46, "angel"}},
     std::map <int, std::string>{{0x47, "Bullet-Proof"}},
     std::map <int, std::string>{{0x49, "irem"}},
     std::map <int, std::string>{{0x50, "Absolute"}},
     std::map <int, std::string>{{0x51, "Acclaim"}},
     std::map <int, std::string>{{0x52, "Activision"}},
     std::map <int, std::string>{{0x53, "American sammy"}},
     std::map <int, std::string>{{0x54, "Konami"}},
     std::map <int, std::string>{{0x55, "Hi tech entertainment"}},
     std::map <int, std::string>{{0x56, "LJN"}},
     std::map <int, std::string>{{0x57, "Matchbox"}},
     std::map <int, std::string>{{0x58, "Mattel"}},
     std::map <int, std::string>{{0x59, "Milton Bradley"}},
     std::map <int, std::string>{{0x60, "Titus"}},
     std::map <int, std::string>{{0x61, "Virgin"}},
     std::map <int, std::string>{{0x64, "LucasArts"}},
     std::map <int, std::string>{{0x67, "Ocean"}},
     std::map <int, std::string>{{0x69, "Electronic Arts"}},
     std::map <int, std::string>{{0x70, "Infogrames"}},
     std::map <int, std::string>{{0x71, "Interplay"}},
     std::map <int, std::string>{{0x72, "Broderbund"}},
     std::map <int, std::string>{{0x73, "sculptured"}},
     std::map <int, std::string>{{0x75, "sci"}},
     std::map <int, std::string>{{0x78, "THQ"}},
     std::map <int, std::string>{{0x79, "Accolade"}},
     std::map <int, std::string>{{0x80, "misawa"}},
     std::map <int, std::string>{{0x83, "lozc"}},
     std::map <int, std::string>{{0x86, "Tokuma Shoten Intermedia"}},
     std::map <int, std::string>{{0x87, "Tsukuda Original"}},
     std::map <int, std::string>{{0x91, "Chunsoft"}},
     std::map <int, std::string>{{0x92, "Video system"}},
     std::map <int, std::string>{{0x93, "Ocean/Acclaim"}},
     std::map <int, std::string>{{0x95, "Varie"}},
     std::map <int, std::string>{{0x96, "Yonezawa/s’pal"}},
     std::map <int, std::string>{{0x97, "Kaneko"}},
     std::map <int, std::string>{{0x99, "Pack in soft"}},
     std::map <int, std::string>{{0xA4, "Konami"}},
    };

//hopefully accessing rom_header from here will work
static rom_header ctx;
//hopefully accessing rom_header from here will work
bool cart_load(char *cart) 
{
    snprintf(ctx.filename, sizeof(ctx.filename), "%s", cart);
    
    std::FILE *fp = fopen(cart,"r");
};
//rom_data = malloc(cart_desc.rom_size)
