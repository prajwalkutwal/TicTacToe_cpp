#include <iostream>
#include <string>
using namespace std;


int main()
{
    int choice;
    char GameBoard[SQUARES] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; 
  
    char playerpiece, computerpiece, currentplayer;
    playerpiece = Introduction();     
    if(playerpiece == 'X')  { computerpiece = 'O'; }
    else { computerpiece = 'X'; }
    
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
        
        if(currentplayer == playerpiece) { currentplayer = computerpiece; }
        else { currentplayer = playerpiece; }
    }

    DisplayWinner(CheckForAWinner(GameBoard), computerpiece, playerpiece);

    cout << "\nGame Over.\n\n"
         << "Exiting Tic Tac Toe ...\n\n\n";
         
    system("PAUSE");
    return 0;
}