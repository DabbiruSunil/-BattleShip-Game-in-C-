##Battleship Game in C++

Welcome to the Battleship Game project! This repository contains the source code for a single-player Battleship game implemented in C++. The game includes features such as shooting mechanisms, game state display, and ship layout, providing an engaging experience for players.

##Table of Contents

Introduction
Features
Installation
Usage
File Structure
Contributing
Acknowledgements

##Introduction

Battleship is a classic naval combat game where the player's objective is to sink all of the opponent's ships. This project is a C++ object-oriented model of the Battleship game designed for single-player mode. The player will compete against a computer-controlled opponent.

##Features

Shooting Mechanisms: Players can target and shoot at the opponent's grid.
Game State Display: The game provides visual feedback on the state of the player's and opponent's grids.
Ship Layout: Ships are placed on the grid, and players must guess their locations to win.

##Installation

To run the Battleship game, follow these steps:

Clone the repository:

git clone https://github.com/DabbiruSunil/Battleship-Game-in-C-.git
cd Battleship-Game-in-C-

Compile the source code:

g++ -o battleship main.cpp Board.cpp ConsoleView.cpp GridPosition.cpp OpponentGrid.cpp OwnGrid.cpp Ship.cpp Shot.cpp part1tests.cpp part2tests.cpp part3tests.cpp

Run the game:
./battleship


##Usage

After running the game, follow the on-screen instructions to play. You will be prompted to enter grid positions to shoot at the opponent's ships. The game will display the state of both grids after each turn.

##File Structure

main.cpp: The main entry point for the game.
Board.cpp / Board.h: Handles the game board and ship placements.
ConsoleView.cpp / ConsoleView.h: Manages the display of the game state on the console.
GridPosition.cpp / GridPosition.h: Defines positions on the grid.
OpponentGrid.cpp / OpponentGrid.h: Manages the opponent's grid and logic.
OwnGrid.cpp / OwnGrid.h: Manages the player's grid and logic.
Ship.cpp / Ship.h: Represents ships on the grid.
Shot.cpp / Shot.h: Represents shots fired at the grid.
part1tests.cpp, part2tests.cpp, part3tests.cpp: Test files for various components of the game.
AllTests.h: Header file for test integration.

##Contributing

Contributions are welcome! If you have suggestions for improvements or want to report issues, please open an issue or submit a pull request.



##Acknowledgements

This project was created as part of a college assignment. Special thanks to the course instructors and teaching assistants for their guidance.
