# Tic Tac Toe (C++ with Minimax AI)

This is a simple command-line Tic Tac Toe game implemented in C++. The game allows a human player (`X`) to play against an AI opponent (`O`) that uses the **Minimax algorithm** to make optimal moves.

## Features
- Play against a smart AI using **Minimax**.
- Simple **text-based interface**.
- Detects **win, loss, or draw** conditions.
- **Validates user input** to prevent invalid moves.

## How to Play
1. Run the program.
2. The game board is displayed with positions numbered **0 to 8**.
3. Enter a number (0-8) to place your move (`X`).
4. The AI (`O`) will make its move automatically.
5. The game continues until **someone wins or the board is full**.
6. The winner or a draw result is displayed.

## Compilation & Execution

### Using g++
To compile the program, use:
```sh
g++ tictactoe.cpp -o tictactoe
```
To run:
```sh
./tictactoe
```

## Example Gameplay

```
Welcome to Tic Tac Toe!
You are 'X' and the computer is 'O'.
The board positions are numbered as follows:
 0 | 1 | 2
---+---+---
 3 | 4 | 5
---+---+---
 6 | 7 | 8

Enter your move (0-8): 0

 X |   |  
---+---+---
   |   |  
---+---+---
   |   |  

Computer placed 'O' in position 4.

 X |   |  
---+---+---
   | O |  
---+---+---
   |   |  
...
```

## Algorithm Explanation
The AI uses the **Minimax algorithm** to make optimal moves:
- **Evaluates** all possible moves.
- **Chooses the move** that minimizes the opponent’s chance of winning.
- **Prevents losing** when possible.
- **Always plays optimally**, making it impossible to defeat.


