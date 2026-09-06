# Pong C++

A simple two-player Pong implementation written in modern C++ using Raylib.

## Features

- Two-player local multiplayer
- W/S controls for the left paddle
- Up/Down controls for the right paddle
- Score tracking
- First player to the winning score wins
- Restart matches without restarting the application
- Raylib automatically fetched through CMake

## Requirements

- C++23-compatible compiler
- CMake
- Git

Raylib is downloaded automatically during configuration.

## Building

git clone https://github.com/PixelBrewer/Pong-Cpp.git
cd Pong-Cpp

cmake -S . -B build
cmake --build build --config Release

## Controls

| Player | Up | Down |
| --- | --- | --- |
| Left Paddle | W | S |
| Right Paddle | Up Arrow | Down Arrow |

Press Space to start.

Press R after a match to restart.

## Built With

- C++23
- Raylib 6.0
- CMake

## License

MIT
