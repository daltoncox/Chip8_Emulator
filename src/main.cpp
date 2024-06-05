/*
Second attempt at a chip 8 emulator
*/
#include <iomanip>
#include <iostream>

#include "Chip8CPU.h"
#include "Window.h"
using namespace std;

int main() {
    cout << "Running Emulator" << endl;

    Chip8CPU processor;
    processor.LoadROM("roms/pong.rom");

    while (processor.Cycle());
    return 0;
}