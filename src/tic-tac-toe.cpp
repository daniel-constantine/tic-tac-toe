//Programmer: Daniel Constantine
//Contact: daniel.k.constantine@gmail.com
//Date: June 8, 2017
//This program asks user if he/she wants to play tic-tac-toe game where they can play
//against themselves, against computer with three difficulties(easy, normal, and hard), or watching computer plays against themselves.
//This is version 2.0 from my previous Tic Tac Toe, in this code I separated the function for playing the game in different class
//and also in new code, there is new additional difficulties the user can choose to play around
//Future plan for this Tic Tac Toe is implementing and creating better interface for the user.
#include "Game.h"

int main()
{
    Game firstGame; //creating an object called firstGame based on Game class
    firstGame.startGame();
    return 0;
}
