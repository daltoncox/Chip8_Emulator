# Chip8 Emulator

A simple and educational Chip-8 emulator written in C++. This project aims to replicate the functionality of the original Chip-8 virtual machine, allowing you to run classic Chip-8 games and programs.

## Features

- Fully interprets Chip-8 opcodes
- Loads and runs Chip-8 ROMs
- Keyboard input mapping
- Basic graphics display (monochrome)

## Getting Started

### Prerequisites

- C++ compiler (C++11 or newer recommended)
- SDL2 library (for graphics and input)

### Building

```bash
git clone https://github.com/daltoncox/Chip8_Emulator.git
cd Chip8_Emulator
# Build instructions may vary depending on your system,
# e.g., using Makefile or your favorite IDE.
```

### Running

```bash
./chip8 path/to/rom.ch8
```

## Controls

- Standard Chip-8 keypad mapped to your keyboard (details in code/config).

## License

This project is licensed under the MIT License.
