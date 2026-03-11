#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char turn;
    bool draw;

public:
    TicTacToe() {
        // Initialize board with numbers 1-9
        char count = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = count++;
        turn = 'X';
        draw = false;
    }

    void displayBoard() {
        system("cls"); // use "clear" if on Linux
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << "     |     |     \n";
            for (int j = 0; j < 3; j++) {
                cout << "  " << board[i][j] << "  ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "_____|_____|_____\n";
            else cout << "     |     |     \n";
        }
    }

    void playerTurn() {
        int choice;
        cout << "\nPlayer " << turn << "'s turn. Enter your choice: ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            playerTurn(); // can also use a loop instead of recursion
        } else {
            board[row][col] = turn;
            turn = (turn == 'X') ? 'O' : 'X';
        }
    }

    bool gameOver() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return false;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return false;
        }
        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return false;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return false;

        // Check for draw
        draw = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    draw = false;

        if (draw) return false; // game over with draw

        return true; // continue playing
    }

    void announceResult() {
        displayBoard();
        if (draw) {
            cout << "Game Draw!\n";
        } else {
            // Previous player made the winning move
            char winner = (turn == 'X') ? 'O' : 'X';
            cout << "Player " << winner << " wins! Congratulations!\n";
        }
    }

    void play() {
        while (gameOver()) {
            displayBoard();
            playerTurn();
        }
        announceResult();
    }
};

int main() {
    TicTacToe game;
    cout << "================== Welcome to Tic Tac Toe Game! ==================\n";
    game.play();
    return 0;
}