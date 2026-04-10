#include <iostream>
#include <string>
#include <limits>
using namespace std;

class TicTacToe
{
private:
    string player1, player2;
    char board[3][3];
    char turn;
    bool draw;

public:
    TicTacToe()
    {
        cout << "Enter Player 1 Name (X): ";
        getline(cin, player1);

        cout << "Enter Player 2 Name (O): ";
        getline(cin, player2);

        char count = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = count++;

        turn = 'X';
        draw = false;
    }

    void displayBoard()
    {
        system("cls");
        cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "     |     |     \n";
            for (int j = 0; j < 3; j++)
            {
                cout << "  " << board[i][j] << "  ";
                if (j < 2)
                    cout << "|";
            }
            cout << "\n";
            if (i < 2)
                cout << "_____|_____|_____\n";
            else
                cout << "     |     |     \n";
        }
    }

    void playerTurn()
    {
        int choice;

        while (true)
        {
            if (turn == 'X')
                cout << "\n" << player1 << " (X)'s turn. Enter your choice: ";
            else
                cout << "\n" << player2 << " (O)'s turn. Enter your choice: ";

            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a number from 1 to 9.\n";
                continue;
            }

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O')
            {
                board[row][col] = turn;
                turn = (turn == 'X') ? 'O' : 'X';
                break;
            }
            else
            {
                cout << "Invalid move! Try again.\n";
            }
        }
    }

    bool gameOver()
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return false;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return false;
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return false;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return false;

        draw = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    draw = false;

        if (draw)
            return false;

        return true;
    }

    void announceResult()
    {
        displayBoard();
        if (draw)
        {
            cout << "Game Draw!\n";
        }
        else
        {
            char winner = (turn == 'X') ? 'O' : 'X';
            if (winner == 'X')
                cout << player1 << " wins! Congratulations!\n";
            else
                cout << player2 << " wins! Congratulations!\n";
        }
    }

    void play()
    {
        while (gameOver())
        {
            displayBoard();
            playerTurn();
        }
        announceResult();
    }
};

int main()
{
    char choice;

    cout << "================== Welcome to Tic Tac Toe Game! ==================\n";

    do
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        TicTacToe game;
        game.play();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
