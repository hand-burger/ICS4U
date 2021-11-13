// Tic tac toe game

#include <iostream>

using namespace std;

int main()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int move = 0;
    int game = 1;
    int row = 0;
    int col = 0;
    int win = 0;

    while (game)
    {
        cout << "Player " << player << "'s turn" << endl;
        cout << "Enter row and column: ";
        cin >> row >> col;

        if (board[row][col] == 0)
        {
            board[row][col] = player;
            move++;
        }
        else
        {
            cout << "Invalid move" << endl;
            continue;
        }

        if (move == 9)
        {
            cout << "Tie game" << endl;
            game = 0;
        }

        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }

        win = 0;

        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                win = 1;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                win = 1;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            win = 1;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            win = 1;
        }

        if (win == 1)
        {
            cout << "Player " << player << " wins!" << endl;
            game = 0;
        }
    }

    return 0;
}