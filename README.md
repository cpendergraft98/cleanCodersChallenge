# Minimax-Based Tic-Tac-Toe Agent and Game

A simple yet complete Tic-Tac-Toe game implemented with C++ and the Qt6 framework. Inculdes a Start Window, a Main Game Window, a Minimax-Based AI opponent, and a Game End screen. Built for linux, but can be ported to Windows and MacOS.

## Features

- Play against an unbeatable AI opponent
- Modern GUI with Qt6 Widgets
- Start menu and end-of-game results screen
- Replay or exit after finishing a game
- Fully memory-managed - no leaks, clean restarts
- Professional-quality event and loop lifecycle control
- Designed to be easily extended

---

## Requirements

- C++17 compatible compiler
- CMake (3.14 or newer)
- Qt6 libraries (Widgets, Core, etc.)

---

## Building the Project for Linux

Clone the repository:

```bash

git clone https://github.com/cpendergraft98/cleanCodersChallenge.git
cd cleanCodersChallenge
```

Create a build directory and compile:

```bash
cmake -S . -B build
cmake --build build
```

Run the executable

```bash
cd build
./TicTacToe
```
---

## Building the Project for macOS

The source code is fully cross-platform and designed to compile cleanly on macOS.

Install Qt and CMake:

```bash
brew install cmake
brew install qt
```

Clone the repository:

```bash

git clone https://github.com/cpendergraft98/cleanCodersChallenge.git
cd cleanCodersChallenge
```

Create a build directory and compile:

```bash
cmake -S . -B build
cmake --build build
```

Run the executable

```bash
cd build
./TicTacToe
```
---

## How to Play

1. Launch the game.
2. Choose "Play" to start a new game
3. The game will randomly determine if you or the opponent moves first.
4. On your turn, click on a cell to place your mark ('X').
5. Lose, draw, or win (good luck) - the result will be displayed at the end of the game.
6. Choose to replay or exit the game.
