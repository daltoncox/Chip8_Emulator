// Chip8CPU implementation file
#include "Chip8CPU.h"

#include <fstream>
#include <iomanip>
#include <iostream>

Chip8CPU::Chip8CPU() { ProgramCounter = 0x200; }

bool Chip8CPU::LoadROM(string romname) {
    ifstream inFile;

    // opens the file in binary mode
    inFile.open(romname, ios_base::binary);
    if (!inFile) {
        cout << "ERROR: File Failed to Open" << endl;
        return false;
    }

    // determines the size of the file
    inFile.seekg(0, ios::end);         // sets position in the stream to the end
    streamsize size = inFile.tellg();  // sets size to the position
    inFile.seekg(0);                   // sets position to the beggining

    // creates a buffer and reads to it
    char* buffer = new char[size];
    inFile.read(buffer, size);
    cout << size << " bytes read from file" << endl;

    // copies buffer to memory and deletes buffer
    for (int i = 0; i < size; i++) {
        ROM[0x200 + i] = buffer[i];
    }
    delete[] buffer;

    for (int i; i < size; i++) {
        if (i % 16 == 0) cout << endl;
        cout << hex << setw(2) << setfill('0') << (int)ROM[i + 0x200];
        cout << ' ';
    }
    cout << endl << endl;

    return true;
}

bool Chip8CPU::Cycle() {
    DebugMenu();

    if (!ProcessOpcode(GetNextOpcode())) return false;
    if (soundTIMER > 0) soundTIMER--;
    if (delayTIMER > 0) delayTIMER--;
    return true;
}

void Chip8CPU::SetKey(short key, bool value) { Key[key] = value; }

uint32_t* Chip8CPU::GetScreen() { return Screen; }

uint16_t Chip8CPU::GetNextOpcode() {
    uint16_t opcode;
    opcode = ROM[ProgramCounter];
    opcode <<= 8;
    opcode |= ROM[ProgramCounter + 1];

    ProgramCounter += 2;
    return opcode;
}
bool Chip8CPU::ProcessOpcode(uint16_t opcode) {
    switch (opcode & 0xF000) {
        case 0x0000:
            switch (opcode & 0x000F) {
                case 0x0000:
                    opcode00E0();
                    break;
                case 0x000E:
                    opcode00EE();
                    break;
                default:
                    cout << "ERROR: Opcode not found in 0" << endl;
                    return false;
            }
            break;
        case 0x1000:
            opcode1NNN(opcode);
            break;
        case 0x2000:
            opcode2NNN(opcode);
            break;
        case 0x3000:
            opcode3XNN(opcode);
            break;
        case 0x4000:
            opcode4XNN(opcode);
            break;
        case 0x5000:
            opcode5XY0(opcode);
            break;
        case 0x6000:
            opcode6XNN(opcode);
            break;
        case 0x7000:
            opcode7XNN(opcode);
            break;
        case 0x8000:
            switch (opcode & 0x000F) {
                case 0x0000:
                    opcode8XY0(opcode);
                    break;
                case 0x0001:
                    opcode8XY1(opcode);
                    break;
                case 0x0002:
                    opcode8XY2(opcode);
                    break;
                case 0x0003:
                    opcode8XY3(opcode);
                    break;
                case 0x0004:
                    opcode8XY4(opcode);
                    break;
                case 0x0005:
                    opcode8XY5(opcode);
                    break;
                case 0x0006:
                    opcode8XY6(opcode);
                    break;
                case 0x0007:
                    opcode8XY7(opcode);
                    break;
                case 0x000E:
                    opcode8XYE(opcode);
                    break;
                default:
                    cout << "ERROR: Opcode not found in 8" << endl;
                    return false;
            }
            break;
        case 0x9000:
            opcode9XY0(opcode);
            break;
        case 0xA000:
            opcodeANNN(opcode);
            break;
        case 0xB000:
            opcodeBNNN(opcode);
            break;
        case 0xC000:
            opcodeCXNN(opcode);
            break;
        case 0xD000:
            opcodeDXYN(opcode);
            break;
        case 0xE000:
            switch (opcode & 0x000F) {
                case 0x000E:
                    opcodeEX9E(opcode);
                    break;
                case 0x0001:
                    opcodeEXA1(opcode);
                    break;
                default:
                    cout << "ERROR: Opcode not found in E" << endl;
                    return false;
            }
            break;
        case 0xF000:
            switch (opcode & 0x00FF) {
                case 0x0007:
                    opcodeFX07(opcode);
                    break;
                case 0x000A:
                    opcodeFX0A(opcode);
                    break;
                case 0x0015:
                    opcodeFX15(opcode);
                    break;
                case 0x0018:
                    opcodeFX18(opcode);
                    break;
                case 0x001E:
                    opcodeFX1E(opcode);
                    break;
                case 0x0029:
                    opcodeFX29(opcode);
                    break;
                case 0x0033:
                    opcodeFX33(opcode);
                    break;
                case 0x0055:
                    opcodeFX55(opcode);
                    break;
                case 0x0065:
                    opcodeFX65(opcode);
                    break;
                default:
                    cout << "ERROR: Opcode not found in F" << endl;
                    return false;
            }
            break;
        default:
            cout << "ERROR: Opcode not found" << endl;
            return false;
    }
    return true;
}

// Clears the screen.
void Chip8CPU::opcode00E0() { return; }

// Returns from a subroutine.
void Chip8CPU::opcode00EE() { return; }

// Jumps to address NNN.
void Chip8CPU::opcode1NNN(uint16_t opcode) { return; }

// Calls subroutine at NNN.
void Chip8CPU::opcode2NNN(uint16_t opcode) { return; }

// Skips the next instruction if VX equals NN
void Chip8CPU::opcode3XNN(uint16_t opcode) { return; }

// Skips the next instruction if VX does not equal NN
void Chip8CPU::opcode4XNN(uint16_t opcode) { return; }

// Skips the next instruction if VX equals VY
void Chip8CPU::opcode5XY0(uint16_t opcode) { return; }

// Sets VX to NN
void Chip8CPU::opcode6XNN(uint16_t opcode) { return; }

// Adds NN to VX (carry flag is not changed)
void Chip8CPU::opcode7XNN(uint16_t opcode) { return; }

// Sets VX to the value of VY
void Chip8CPU::opcode8XY0(uint16_t opcode) { return; }

// Sets VX to VX or VY. (bitwise OR operation)
void Chip8CPU::opcode8XY1(uint16_t opcode) { return; }

// Sets VX to VX and VY. (bitwise AND operation)
void Chip8CPU::opcode8XY2(uint16_t opcode) { return; }

// Sets VX to VX xor VY
void Chip8CPU::opcode8XY3(uint16_t opcode) { return; }

// Adds VY to VX. VF is set to 1 when there's an overflow, and to 0 when there
// is not
void Chip8CPU::opcode8XY4(uint16_t opcode) { return; }

// VY is subtracted from VX. VF is set to 0 when there's an underflow, and 1
// when there is not. (i.e. VF set to 1 if VX >= VY and 0 if not)
void Chip8CPU::opcode8XY5(uint16_t opcode) { return; }

// Shifts VX to the right by 1, then stores the least significant bit of VX
// prior to the shift into VF.
void Chip8CPU::opcode8XY6(uint16_t opcode) { return; }

// Sets VX to VY minus VX. VF is set to 0 when there's an underflow, and 1 when
// there is not. (i.e. VF set to 1 if VY >= VX)
void Chip8CPU::opcode8XY7(uint16_t opcode) { return; }

// Shifts VX to the left by 1, then sets VF to 1 if the most significant bit of
// VX prior to that shift was set, or to 0 if it was unset.
void Chip8CPU::opcode8XYE(uint16_t opcode) { return; }

// Skips the next instruction if VX does not equal VY. (Usually the next
// instruction is a jump to skip a code block).
void Chip8CPU::opcode9XY0(uint16_t opcode) { return; }

// Sets I to the address NNN.
void Chip8CPU::opcodeANNN(uint16_t opcode) { return; }

// Jumps to the address NNN plus V0.
void Chip8CPU::opcodeBNNN(uint16_t opcode) { return; }

// Sets VX to the result of a bitwise and operation on a random number
// (Typically: 0 to 255) and NN
void Chip8CPU::opcodeCXNN(uint16_t opcode) { return; }

// Draws a sprite at coordinate (VX, VY) that has a width of 8 pixels and a
// height of N pixels. Each row of 8 pixels is read as bit-coded starting from
// memory location I; I value does not change after the execution of this
// instruction. As described above, VF is set to 1 if any screen pixels are
// flipped from set to unset when the sprite is drawn, and to 0 if that does not
// happen.
void Chip8CPU::opcodeDXYN(uint16_t opcode) { return; }

// Skips the next instruction if the key stored in VX is pressed
void Chip8CPU::opcodeEX9E(uint16_t opcode) { return; }

// Skips the next instruction if the key stored in VX is not pressed
void Chip8CPU::opcodeEXA1(uint16_t opcode) { return; }

// Sets VX to the value of the delay timer
void Chip8CPU::opcodeFX07(uint16_t opcode) { return; }

// A key press is awaited, and then stored in VX (blocking operation, all
// instruction halted until next key event)
void Chip8CPU::opcodeFX0A(uint16_t opcode) { return; }

// Sets the delay timer to VX.
void Chip8CPU::opcodeFX15(uint16_t opcode) { return; }

// Sets the sound timer to VX
void Chip8CPU::opcodeFX18(uint16_t opcode) { return; }

// Adds VX to I. VF is not affected
void Chip8CPU::opcodeFX1E(uint16_t opcode) { return; }

// Sets I to the location of the sprite for the character in VX. Characters 0-F
// (in hexadecimal) are represented by a 4x5 font
void Chip8CPU::opcodeFX29(uint16_t opcode) { return; }

// Stores the binary-coded decimal representation of VX, with the hundreds digit
// in memory at location in I, the tens digit at location I+1, and the ones
// digit at location I+2.
void Chip8CPU::opcodeFX33(uint16_t opcode) { return; }

// Stores from V0 to VX (including VX) in memory, starting at address I. The
// offset from I is increased by 1 for each value written, but I itself is left
// unmodified.
void Chip8CPU::opcodeFX55(uint16_t opcode) { return; }

// Fills from V0 to VX (including VX) with values from memory, starting at
// address I. The offset from I is increased by 1 for each value read, but I
// itself is left unmodified
void Chip8CPU::opcodeFX65(uint16_t opcode) { return; }

void Chip8CPU::DebugMenu() {
    uint16_t opcode;
    opcode = ROM[ProgramCounter];
    opcode <<= 8;
    opcode |= ROM[ProgramCounter + 1];

    cout << hex << setw(4) << setfill('0') << (int)opcode << endl;
    return;
}