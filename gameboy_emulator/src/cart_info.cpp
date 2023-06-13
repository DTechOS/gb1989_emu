#include <cartinfo.h>
#include <iostream>
#include <string>
#include <map>


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
std::map<int, std::string> old_ic_code[] {
     std::map<int, std::string>{{0x00, "None"}},
     std::map<int, std::string>{{0x01, "Nintendo"}},
     std::map<int, std::string>{{0x08, "Capcom"}},
     std::map<int, std::string>{{0x09, "Hot-B"}},
     std::map<int, std::string>{{0x0A, "Jaleco"}},
     std::map<int, std::string>{{0x0B, "Coconuts Japan"}},
     std::map<int, std::string>{{0x0C, "Elite Systems"}},
     std::map<int, std::string>{{0x13, "EA (Electronic Arts)"}},
     std::map<int, std::string>{{0x18, "Hudsonsoft"}},
     std::map<int, std::string>{{0x19, "ITC Entertainment"}},
     std::map<int, std::string>{{0x1A, "Yanoman"}},
     std::map<int, std::string>{{0x1D, "Japan Clary"}},
     std::map<int, std::string>{{0x1F, "Virgin Interactive"}},
     std::map<int, std::string>{{0x24, "PCM Complete"}},
     std::map<int, std::string>{{0x25, "San-X"}},
     std::map<int, std::string>{{0x28, "Kotobuki Systems"}},
     std::map<int, std::string>{{0x29, "Seta"}},
     std::map<int, std::string>{{0x30, "Infogrames"}},
     std::map<int, std::string>{{0x31, "Nintendo"}},
     std::map<int, std::string>{{0x32, "Bandai"}},
     std::map<int, std::string>{{0x33, "OLD LIC CODE"}},
     std::map<int, std::string>{{0x34, "Konami"}},
     std::map<int, std::string>{{0x35, "HectorSoft"}},
     std::map<int, std::string>{{0x38, "Capcom"}},
     std::map<int, std::string>{{0x39, "Banpresto"}},
     std::map<int, std::string>{{0x3C, ".Entertainment i"}},
     std::map<int, std::string>{{0x3E, "Gremlin"}},
     std::map<int, std::string>{{0x41, "Ubisoft"}},
     std::map<int, std::string>{{0x42, "Atlus"}},
     std::map<int, std::string>{{0x44, "Malibu"}},
     std::map<int, std::string>{{0x46, "Angel"}},
     std::map<int, std::string>{{0x47, "Spectrum Holoby"}},
     std::map<int, std::string>{{0x49, "Irem"}},
     std::map<int, std::string>{{0x4A, "Virgin Interactive"}},
     std::map<int, std::string>{{0x4D, "Malibu"}},
     std::map<int, std::string>{{0x4F, "U.S. Gold"}},
     std::map<int, std::string>{{0x50, "Absolute"}},
     std::map<int, std::string>{{0x51, "Acclaim"}},
     std::map<int, std::string>{{0x52, "Activision"}},
     std::map<int, std::string>{{0x53, "American Sammy"}},
     std::map<int, std::string>{{0x54, "GameTek"}},
     std::map<int, std::string>{{0x55, "Park Place"}},
     std::map<int, std::string>{{0x56, "LJN"}},
     std::map<int, std::string>{{0x57, "Matchbox"}},
     std::map<int, std::string>{{0x59, "Milton Bradley"}},
     std::map<int, std::string>{{0x5A, "Mindscape"}},
     std::map<int, std::string>{{0x5B, "Romstar"}},
     std::map<int, std::string>{{0x5C, "Naxat Soft"}},
     std::map<int, std::string>{{0x5D, "Tradewest"}},
     std::map<int, std::string>{{0x60, "Titus"}},
     std::map<int, std::string>{{0x61, "Virgin Interactive"}},
     std::map<int, std::string>{{0x67, "Ocean Interactive"}},
     std::map<int, std::string>{{0x69, "EA (Electronic Arts)"}},
     std::map<int, std::string>{{0x6E, "Elite Systems"}},
     std::map<int, std::string>{{0x6F, "Electro Brain"}},
     std::map<int, std::string>{{0x70, "Infogrames"}},
     std::map<int, std::string>{{0x71, "Interplay"}},
     std::map<int, std::string>{{0x72, "Broderbund"}},
     std::map<int, std::string>{{0x73, "Sculptered Soft"}},
     std::map<int, std::string>{{0x75, "The Sales Curve"}},
     std::map<int, std::string>{{0x78, "t.hq"}},
     std::map<int, std::string>{{0x79, "Accolade"}},
     std::map<int, std::string>{{0x7A, "Triffix Entertainment"}},
     std::map<int, std::string>{{0x7C, "Microprose"}},
     std::map<int, std::string>{{0x7F, "Kemco"}},
     std::map<int, std::string>{{0x80, "Misawa Entertainment"}},
     std::map<int, std::string>{{0x83, "Lozc"}},
     std::map<int, std::string>{{0x86, "Tokuma Shoten Intermedia"}},
     std::map<int, std::string>{{0x8B, "Bullet-Proof Software"}},
     std::map<int, std::string>{{0x8C, "Vic Tokai"}},
     std::map<int, std::string>{{0x8E, "Ape"}},
     std::map<int, std::string>{{0x8F, "I’Max"}},
     std::map<int, std::string>{{0x91, "Chunsoft Co."}},
     std::map<int, std::string>{{0x92, "Video System"}},
     std::map<int, std::string>{{0x93, "Tsubaraya Productions Co."}},
     std::map<int, std::string>{{0x95, "Varie Corporation"}},
     std::map<int, std::string>{{0x96, "Yonezawa/S’Pal"}},
     std::map<int, std::string>{{0x97, "Kaneko"}},
     std::map<int, std::string>{{0x99, "Arc"}},
     std::map<int, std::string>{{0x9A, "Nihon Bussan"}},
     std::map<int, std::string>{{0x9B, "Tecmo"}},
     std::map<int, std::string>{{0x9C, "Imagineer"}},
     std::map<int, std::string>{{0x9D, "Banpresto"}},
     std::map<int, std::string>{{0x9F, "Nova"}},
     std::map<int, std::string>{{0xA1, "Hori Electric"}},
     std::map<int, std::string>{{0xA2, "Bandai"}},
     std::map<int, std::string>{{0xA4, "Konami"}},
     std::map<int, std::string>{{0xA6, "Kawada"}},
     std::map<int, std::string>{{0xA7, "Takara"}},
     std::map<int, std::string>{{0xA9, "Technos Japan"}},
     std::map<int, std::string>{{0xAA, "Broderbund"}},
     std::map<int, std::string>{{0xAC, "Toei Animation"}},
     std::map<int, std::string>{{0xAD, "Toho"}},
     std::map<int, std::string>{{0xAF, "Namco"}},
     std::map<int, std::string>{{0xB0, "acclaim"}},
     std::map<int, std::string>{{0xB1, "ASCII or Nexsoft"}},
     std::map<int, std::string>{{0xB2, "Bandai"}},
     std::map<int, std::string>{{0xB4, "Square Enix"}},
     std::map<int, std::string>{{0xB6, "HAL Laboratory"}},
     std::map<int, std::string>{{0xB7, "SNK"}},
     std::map<int, std::string>{{0xB9, "Pony Canyon"}},
     std::map<int, std::string>{{0xBA, "Culture Brain"}},
     std::map<int, std::string>{{0xBB, "Sunsoft"}},
     std::map<int, std::string>{{0xBD, "Sony Imagesoft"}},
     std::map<int, std::string>{{0xBF, "Sammy"}},
     std::map<int, std::string>{{0xC0, "Taito"}},
     std::map<int, std::string>{{0xC2, "Kemco"}},
     std::map<int, std::string>{{0xC3, "Squaresoft"}},
     std::map<int, std::string>{{0xC4, "Tokuma Shoten Intermedia"}},
     std::map<int, std::string>{{0xC5, "Data East"}},
     std::map<int, std::string>{{0xC6, "Tonkinhouse"}},
     std::map<int, std::string>{{0xC8, "Koei"}},
     std::map<int, std::string>{{0xC9, "UFL"}},
     std::map<int, std::string>{{0xCA, "Ultra"}},
     std::map<int, std::string>{{0xCB, "Vap"}},
     std::map<int, std::string>{{0xCC, "Use Corporation"}},
     std::map<int, std::string>{{0xCD, "Meldac"}},
     std::map<int, std::string>{{0xCE, ".Pony Canyon or"}},
     std::map<int, std::string>{{0xCF, "Angel"}},
     std::map<int, std::string>{{0xD0, "Taito"}},
     std::map<int, std::string>{{0xD1, "Sofel"}},
     std::map<int, std::string>{{0xD2, "Quest"}},
     std::map<int, std::string>{{0xD3, "Sigma Enterprises"}},
     std::map<int, std::string>{{0xD4, "ASK Kodansha Co."}},
     std::map<int, std::string>{{0xD6, "Naxat Soft"}},
     std::map<int, std::string>{{0xD7, "Copya System"}},
     std::map<int, std::string>{{0xD9, "Banpresto"}},
     std::map<int, std::string>{{0xDA, "Tomy"}},
     std::map<int, std::string>{{0xDB, "LJN"}},
     std::map<int, std::string>{{0xDD, "NCS"}},
     std::map<int, std::string>{{0xDE, "Human"}},
     std::map<int, std::string>{{0xDF, "Altron"}},
     std::map<int, std::string>{{0xE0, "Jaleco"}},
     std::map<int, std::string>{{0xE1, "Towa Chiki"}},
     std::map<int, std::string>{{0xE2, "Yutaka"}},
     std::map<int, std::string>{{0xE3, "Varie"}},
     std::map<int, std::string>{{0xE5, "Epcoh"}},
     std::map<int, std::string>{{0xE7, "Athena"}},
     std::map<int, std::string>{{0xE8, "Asmik ACE Entertainment"}},
     std::map<int, std::string>{{0xE9, "Natsume"}},
     std::map<int, std::string>{{0xEA, "King Records"}},
     std::map<int, std::string>{{0xEB, "Atlus"}},
     std::map<int, std::string>{{0xEC, "Epic/Sony Records"}},
     std::map<int, std::string>{{0xEE, "IGS"}},
     std::map<int, std::string>{{0xF0, "A Wave"}},
     std::map<int, std::string>{{0xF3, "Extreme Entertainment"}},
     std::map<int, std::string>{{0xFF, "LJN"}},
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
