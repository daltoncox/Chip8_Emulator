/*
Second attempt at a chip 8 emulator
*/
#include <chrono>
#include <iostream>

#include "Chip8CPU.h"
#include "Window.h"
using namespace std;

int main() {
    int delayTime = 2;

    cout << "Running Emulator" << endl;

    Chip8CPU processor;
    if (!processor.LoadROM("roms/tetris.rom")) return 1;

    Window window("Chip8_Emulator", 64, 32, 10);

    auto lastCycle = chrono::high_resolution_clock::now();
    float timeSinceLast;

    while (window.ProcessInput(processor.Key)) {
        // processor.Key[1] = 1;
        auto currentTime = chrono::high_resolution_clock::now();
        timeSinceLast = chrono::duration<float, chrono::milliseconds::period>(
                            currentTime - lastCycle)
                            .count();

        if (timeSinceLast > delayTime) {
            lastCycle = currentTime;
            if (!processor.Cycle()) return 2;
            window.UpdateScreen(processor.GetScreen(), 4 * 64);
        }
    }
    return 0;
}