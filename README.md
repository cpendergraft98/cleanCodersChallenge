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

## Cloning the Repository

```bash
git clone https://github.com/cpendergraft98/cleanCodersChallenge.git
```

---

## Execution

For reviewer convenience, a pre-built executable is contained within the repository under `/build/TicTacToe`. Naviagate to the directory using `cd cleanCodersChallenge/build` and execute with `./TicTacToe`.

---

## Self-Build Requirements
- C++17 compatible compiler
- CMake (3.14 or newer)
- Qt6 libraries (Widgets, Core, etc.)
- Linux (currently built/tested for Linux systems)

---

## Self-Build Instructions

### Clone the Repository (see Cloning instructions)

### Create a Build Directory and Compile

```bash
cmake -S . -B build
cmake --build build
```

### Run the Executable

```Bash
cd Build
./TicTacToe
```

## How to Play

1. Launch the game.
2. Choose "Play" to start a new game
3. The game will randomly determine if you or the opponent moves first.
4. On your turn, click on a cell to place your mark ('X').
5. Lose, draw, or win (good luck) - the result will be displayed at the end of the game.
6. Choose to replay or exit the game.
