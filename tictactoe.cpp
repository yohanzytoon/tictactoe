#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const char PLAYER = 'X';    // Human player
const char COMPUTER = 'O';  // AI player
const char EMPTY = ' ';

// Function to print the Tic Tac Toe board.
void printBoard(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i * 3] << " | " << board[i * 3 + 1] << " | " << board[i * 3 + 2] << " \n";
        if (i != 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check if there are moves left on the board.
bool isMovesLeft(const vector<char>& board) {
    for (char cell : board)
        if (cell == EMPTY)
            return true;
    return false;
}

// Evaluate the board and return a score based on the outcome.
// +10 for a win for COMPUTER, -10 for a win for PLAYER, 0 otherwise.
int evaluate(const vector<char>& board) {
    // Check rows for victory.
    for (int row = 0; row < 3; row++) {
        if (board[row * 3] != EMPTY &&
            board[row * 3] == board[row * 3 + 1] &&
            board[row * 3 + 1] == board[row * 3 + 2]) {
            if (board[row * 3] == COMPUTER)
                return +10;
            else if (board[row * 3] == PLAYER)
                return -10;
        }
    }

    // Check columns for victory.
    for (int col = 0; col < 3; col++) {
        if (board[col] != EMPTY &&
            board[col] == board[col + 3] &&
            board[col + 3] == board[col + 6]) {
            if (board[col] == COMPUTER)
                return +10;
            else if (board[col] == PLAYER)
                return -10;
        }
    }

    // Check diagonals for victory.
    if (board[0] != EMPTY && board[0] == board[4] && board[4] == board[8]) {
        if (board[0] == COMPUTER)
            return +10;
        else if (board[0] == PLAYER)
            return -10;
    }
    if (board[2] != EMPTY && board[2] == board[4] && board[4] == board[6]) {
        if (board[2] == COMPUTER)
            return +10;
        else if (board[2] == PLAYER)
            return -10;
    }

    // No winner: return 0.
    return 0;
}

// The minimax function: returns the best score that the current player can achieve.
int minimax(vector<char>& board, int depth, bool isMax) {
    int score = evaluate(board);

    // If either player has won, return the evaluated score.
    if (score == 10 || score == -10)
        return score;

    // If no moves are left, it's a tie.
    if (!isMovesLeft(board))
        return 0;

    if (isMax) {
        // Maximizer's move (Computer)
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = COMPUTER;
                best = max(best, minimax(board, depth + 1, false));
                board[i] = EMPTY;  // Undo move
            }
        }
        return best;
    } else {
        // Minimizer's move (Human)
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = PLAYER;
                best = min(best, minimax(board, depth + 1, true));
                board[i] = EMPTY;  // Undo move
            }
        }
        return best;
    }
}

// Determine the best move for the computer using the minimax algorithm.
int findBestMove(vector<char>& board) {
    int bestVal = numeric_limits<int>::min();
    int bestMove = -1;

    // Evaluate all possible moves.
    for (int i = 0; i < 9; i++) {
        if (board[i] == EMPTY) {
            board[i] = COMPUTER;
            int moveVal = minimax(board, 0, false);
            board[i] = EMPTY;
            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

int main() {
    // Initialize the board with empty spaces.
    vector<char> board(9, EMPTY);
    int move;

    cout << "Welcome to Tic Tac Toe!\n";
    cout << "You are '" << PLAYER << "' and the computer is '" << COMPUTER << "'.\n";
    cout << "The board positions are numbered as follows:\n";
    cout << " 0 | 1 | 2 \n";
    cout << "---+---+---\n";
    cout << " 3 | 4 | 5 \n";
    cout << "---+---+---\n";
    cout << " 6 | 7 | 8 \n";

    // Print the empty board.
    printBoard(board);

    // Main game loop.
    while (true) {
        // Human player's turn.
        cout << "Enter your move (0-8): ";
        cin >> move;

        // Validate the move.
        if (move < 0 || move > 8 || board[move] != EMPTY) {
            cout << "Invalid move. Please try again.\n";
            continue;
        }

        board[move] = PLAYER;
        printBoard(board);

        // Check if the human player has won.
        if (evaluate(board) == -10) {
            cout << "Congratulations! You win!\n";
            break;
        }
        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // Computer's turn.
        int bestMove = findBestMove(board);
        board[bestMove] = COMPUTER;
        cout << "Computer placed '" << COMPUTER << "' in position " << bestMove << ".\n";
        printBoard(board);

        // Check if the computer has won.
        if (evaluate(board) == 10) {
            cout << "Computer wins! Better luck next time.\n";
            break;
        }
        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
