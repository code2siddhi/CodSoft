#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

void printBanner() {
    cout << "\033[1;34m"; // Blue color for the banner
    cout << "***************************************\n";
    cout << "*                                     *\n";
    cout << "*          \033[1;31mTIC-TAC-TOE GAME\033[1;34m           *\n"; // Red color for the game title
    cout << "*                                     *\n";
    cout << "***************************************\n";
    cout << "\033[0m"; // Reset color
}

void printBoard() {
    cout << "\033[1;36m"; // Cyan color for board lines
    cout << "  1 2 3\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 'X') {
                cout << "\033[1;31m"; // Red color for X
            } else if (board[i][j] == 'O') {
                cout << "\033[1;32m"; // Green color for O
            } else {
                cout << "\033[1;37m"; // White color for empty spaces
            }
            cout << board[i][j];
            if (j < SIZE - 1) cout << "\033[1;36m|"; // Cyan color for board lines
        }
        cout << "\033[1;36m"; // Reset to Cyan color
        cout << "\n";
        if (i < SIZE - 1) cout << "  -----\n";
    }
    cout << "\033[0m"; // Reset color
}

bool isWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char currentPlayer = 'X';
    bool playAgain = true;
    while (playAgain) {
        resetBoard();
        bool gameOngoing = true;
        while (gameOngoing) {
            system("clear"); // For Windows use "cls"
            printBanner();
            printBoard();
            int row, col;
            cout << "\033[1;33mPlayer " << currentPlayer << "'s turn. Enter row and column (1-3): \033[0m";
            cin >> row >> col;
            row--; col--;
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                if (isWin(currentPlayer)) {
                    system("clear"); // For Windows use "cls"
                    printBanner();
                    printBoard();
                    cout << "\033[1;35mPlayer " << currentPlayer << " wins!\033[0m\n"; // Magenta color for win message
                    gameOngoing = false;
                } else if (isDraw()) {
                    system("clear"); // For Windows use "cls"
                    printBanner();
                    printBoard();
                    cout << "\033[1;35mIt's a draw!\033[0m\n"; // Magenta color for draw message
                    gameOngoing = false;
                } else {
                    switchPlayer(currentPlayer);
                }
            } else {
                cout << "\033[1;31mInvalid move. Try again.\033[0m\n"; // Red color for invalid move
            }
        }
        char response;
        cout << "Do you want to play again? (y/n): ";
        cin >> response;
        playAgain = (response == 'y' || response == 'Y');
        currentPlayer = 'X';
    }
    return 0;
}

