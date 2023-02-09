#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;
    // instead of using 2d matrix we can use 1d array and treat it as 2d matrix
    char GameBoard[SQUARES] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    char playerpiece, computerpiece, currentplayer;
    playerpiece = Introduction();
    if (playerpiece == 'X')
    {
        computerpiece = 'O';
    }
    else
    {
        computerpiece = 'X';
    }

    currentplayer = 'X';
    Display(GameBoard);

    while (CheckForAWinner(GameBoard) == 'N')
    {
        if (currentplayer == playerpiece)
        {
            choice = PlayerPlays(GameBoard, playerpiece);
            GameBoard[choice] = playerpiece;
        }
        else
        {
            choice = ComputerPlays(GameBoard, playerpiece, computerpiece);
            GameBoard[choice] = computerpiece;
        }

        Display(GameBoard);

        if (currentplayer == playerpiece)
        {
            currentplayer = computerpiece;
        }
        else
        {
            currentplayer = playerpiece;
        }
    }

    DisplayWinner(CheckForAWinner(GameBoard), computerpiece, playerpiece);

    cout << "\nGame Over.\n\n"
         << "Exiting Tic Tac Toe ...\n\n\n";

    system("PAUSE");
    return 0;
}

char CheckForAWinner(char *GameBoard)
{
    // below are all the winning positions for any player
    const int WINNING_ROWS[8][3] = {{0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6}};
    const int TOTAL_ROWS = 8;
    for (int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ((GameBoard[WINNING_ROWS[row][0]] != ' ') &&
            (GameBoard[WINNING_ROWS[row][0]] == GameBoard[WINNING_ROWS[row][1]]) &&
            (GameBoard[WINNING_ROWS[row][1]] == GameBoard[WINNING_ROWS[row][2]]))
        {
            return GameBoard[WINNING_ROWS[row][0]];
        }
    }
    // If we don't have a winner, check for a possible tie.
    bool NoEmptySpaces = true;

    for (int x = 0; x < SQUARES; x++)
    {
        if (GameBoard[x] == ' ')
        {
            NoEmptySpaces = false;
        }
    }

    if (NoEmptySpaces == true)
        return 'T';

    // If nobdy wins and it's not a tie return 'N' and keep playing.
    return 'N';
}