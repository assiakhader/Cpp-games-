#include <iostream>
#include <vector>
using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    cout << "  1   2   3\n"; // Column numbers
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " "; // Row numbers
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << " ---+---+---\n";
    }
    cout << "\n";
}

// Function to check if there's a winner
bool checkWinner(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 grid initialized with spaces
    char currentPlayer = 'X'; // Player X starts
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n\n";
    displayBoard(board);

    while (!gameOver) {
        int row, col;
        cout << "Player " << currentPlayer << ", it's your turn.\n"; // Fixed single quote issue
        cout << "Enter the row (1-3) and column (1-3) where you want to place your mark: ";
        cin >> row >> col;

        // Validate input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Please try again.\n";
            continue;
        }

        // Place the player's mark
        board[row - 1][col - 1] = currentPlayer;
        displayBoard(board);

        // Check for a winner or tie
        if (checkWinner(board, currentPlayer)) {
            cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (isBoardFull(board)) {
            cout << "It's a tie! Well played both players.\n";
            gameOver = true;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Game over. Thanks for playing!\n";
    return 0;
}
