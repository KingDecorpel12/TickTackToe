//
// Created by Omar Hegazy on 1/28/23.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5',
                             '6'}, {'7','8','9'}};
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void display_board()
{
    // Layout of game board.

    cout << "PLAYER - 1 [X] PLAYER - 2 [O]" << endl;
    cout << "     |     |     ";
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     ";
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     ";
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "     |     |     ";
}

void player_turns()
{
    if(turn == 'X')
    {
        cout << "Player - 1 [X] turn : " << endl;
    }

    else if(turn == 'O')
    {
        cout << "Player - 2 [O] turn : " << endl;
    }

    cin >> choice;

    switch(choice)
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 3; column = 2; break;
        default:
            cout << "Invalid move!" << endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }

    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }

    else
    {
        cout << "Box already filled! Please choose another box!";
        player_turns();
    }

    display_board();
}

bool gameover()
{
    // Checks game results
    for(int i = 0; i < 3; i++)
    {
        // Win by row or column
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }

        // Win by diagonal
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return false;
        }
    }

    // Checks if game is in continue mode or not
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }

    // Checks if game is already a draw
    draw = true;
    return false;
}


int main()
{
    cout << "T I C K -- T A C -- T O E -- G A M E" << " FOR 2 PLAYERS" << endl;

    while(gameover())
    {
        display_board();
        player_turns();
        gameover();
    }

    if(turn == 'X' && draw == false)
    {
        cout << "Congratulations! Player X has won the game!" << endl;
    }

    else if(turn == 'O' && draw == false)
    {
        cout << "Congratulations! Player O has won the game!" << endl;
    }

    else
        cout << "GAME DRAW!!" << endl;
}
