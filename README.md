# Tris - by *ilBuso*

## Table of Content
- [Tris](#tris---by-ilbuso)
  - [Table of Content](#table-of-content)
  - [About](#about)
    - [Key Features:](#key-features)
  - [Usage](#usage)
    - [Download](#download)
    - [Build and Run](#build-and-run)
    - [Gameplay](#gameplay)
    - [Clean Up](#clean-up)

## About

**Tris** is a command-line implementation of the classic Tic-Tac-Toe game, known as "Tris" in Italian. Developed entirely in the C programming language, this game offers a 1vs1 experience, allowing two players to engage in the timeless battle of X and O.

### Key Features:
- **Terminal-Based:** Tris runs only in the terminal.
- **Pure C Development:** The entire game is crafted in the C programming language.
- **Easy to Play:** The game utilizes the numpad for input, making it intuitive and easy to play. Each key corresponds to a cell on the grid, simplifying the move selection process.
- **1vs1 Gameplay:** Enjoy a traditional Tic-Tac-Toe match against a friend, taking turns to make strategic moves on the game board.
- **Leaderboard:** Tris includes a built-in leaderboard that keeps track of victories, adding a competitive edge to the game.


## Usage

### Download
To download, clone this repository to your local computer by running the following command:
```Bash
  git clone https://github.com/ilBuso/Tris.git
```

### Build and Run
Once downloaded, navigate to the Tris directory and compile the program using the following commands:
```Bash
  cd ./Tris
  gcc -Wall -O2 -c main.c
  gcc -Wall -O2 -o tris main.o
```
Alternatively, you can use the provided Makefile with the following commands:
```Bash
  cd ./Tris
  make
```

### Gameplay
Run the compiled Tris executable, eith the following comand:

```Bash
./tris
```
If, for some reason, you are unfamiliar with how to play Tic-Tac-Toe, the program provides both a tutorial and a list of basic rules.

### Clean Up

To clean up the generated files, run the following commands:
```Bash
  rm -f tris main.o
```
Or, if you are using the Makefile, run:
```Bash
  make clean
```
