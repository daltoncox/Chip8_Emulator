#ifndef Chip8CPUHeader
#define Chip8CPUHeader

#include <vector>

#include "Window.h"
using namespace std;
class Chip8CPU {
   public:
    Chip8CPU();

    bool LoadROM(string romname);
    bool Cycle();
    uint32_t* GetScreen();

    uint16_t GetNextOpcode();
    bool ProcessOpcode(uint16_t opcode);

    void opcode00E0();
    void opcode00EE();
    void opcode1NNN(uint16_t opcode);
    void opcode2NNN(uint16_t opcode);
    void opcode3XNN(uint16_t opcode);
    void opcode4XNN(uint16_t opcode);
    void opcode5XY0(uint16_t opcode);
    void opcode6XNN(uint16_t opcode);
    void opcode7XNN(uint16_t opcode);
    void opcode8XY0(uint16_t opcode);
    void opcode8XY1(uint16_t opcode);
    void opcode8XY2(uint16_t opcode);
    void opcode8XY3(uint16_t opcode);
    void opcode8XY4(uint16_t opcode);
    void opcode8XY5(uint16_t opcode);
    void opcode8XY6(uint16_t opcode);
    void opcode8XY7(uint16_t opcode);
    void opcode8XYE(uint16_t opcode);
    void opcode9XY0(uint16_t opcode);
    void opcodeANNN(uint16_t opcode);
    void opcodeBNNN(uint16_t opcode);
    void opcodeCXNN(uint16_t opcode);
    void opcodeDXYN(uint16_t opcode);
    void opcodeEX9E(uint16_t opcode);
    void opcodeEXA1(uint16_t opcode);
    void opcodeFX07(uint16_t opcode);
    void opcodeFX0A(uint16_t opcode);
    void opcodeFX15(uint16_t opcode);
    void opcodeFX18(uint16_t opcode);
    void opcodeFX1E(uint16_t opcode);
    void opcodeFX29(uint16_t opcode);
    void opcodeFX33(uint16_t opcode);
    void opcodeFX55(uint16_t opcode);
    void opcodeFX65(uint16_t opcode);

    void DebugMenu();
    bool Key[16]{};

   private:
    uint8_t ROM[0xFFF]{};
    uint16_t ProgramCounter, AddressI;
    vector<uint16_t> Stack;
    uint8_t Register[16]{};

    uint8_t delayTIMER, soundTIMER;

    uint32_t Screen[64 * 32]{};
};

#endif
