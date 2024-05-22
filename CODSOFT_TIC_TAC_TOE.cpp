#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void printBoard(const vector<vector<char> >& board);
bool placeMark(int row, int col, vector<vector<char> >& board, char currentPlayer);
bool checkWinner(const vector<vector<char> >& board, char currentPlayer);
bool isBoardFull(const vector<vector<char> >& board);
void switchPlayer(char& currentPlayer);

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool gameContinue = true;

    while (gameContinue) {
        cout << "Current player: " << currentPlayer << "\n";
        printBoard(board);

        // Player input
        cout << "Enter row and column [0-2] [0-2]: ";
        cin >> row >> col;

        // Input validation and update board
        while (!placeMark(row, col, board, currentPlayer)) {
            cout << "Invalid move. Try again.\nEnter row and column [0-2] [0-2]: ";
            cin >> row >> col;
        }

        // Check for win or draw
        if (checkWinner(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            printBoard(board);
            gameContinue = false;
        } else if (isBoardFull(board)) {
            cout << "The game is a draw.\n";
            printBoard(board);
            gameContinue = false;
        } else {
            // Switch player
            switchPlayer(currentPlayer);
        }

        // Ask to play again
        if (!gameContinue) {
            char playAgain;
            cout << "Would you like to play again? (y/n): ";
            cin >> playAgain;
            if (playAgain == 'y' || playAgain == 'Y') {
                board = vector<vector<char> >(3, vector<char>(3, ' '));
                gameContinue = true;
                currentPlayer = 'X';  // Reset the first player
            }
        }
    }
    return 0;
}

void printBoard(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
}

bool placeMark(int row, int col, vector<vector<char> >& board, char currentPlayer) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWinner(const vector<vector<char> >& board, char currentPlayer) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return true;
    return false;
}

bool isBoardFull(const vector<vector<char> >& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

