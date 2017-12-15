#include "TTT.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

//default constructor
TTT::TTT(){
    //ctor
}

//asks user what type of game he/she wants to play
int TTT::askUser(){
    int x;
    cout << "Choose what kind of games do you want to play: " << endl;
    cout << "(1) Human vs Human." << endl;
    cout << "(2) Human vs Computer."  << endl;
    cout << "(3) Computer vs Computer." << endl;
    cout << "ENTER your choice: ";
    cin >> x;
    return x;
}

//returns number for player possible of win
int TTT::possWin(char player){
    if((boardGame[0] == boardGame[1]) && (isFree(3))) //012 | 2
		return 3;
	else if((boardGame[0] == boardGame[2]) && (isFree(2)))  //012 | 1
		return 2;
    else if((boardGame[1] == boardGame[2]) && (isFree(1))) //012 | 0
		return 1;
    else if((boardGame[0] == boardGame[3]) && (isFree(7))) //036 | 6
		return 7;
    else if((boardGame[0] == boardGame[6]) && (isFree(4))) //036 | 3
		return 4;
    else if((boardGame[3] == boardGame[6]) && (isFree(1))) //036 | 0
		return 1;
    else if((boardGame[0] == boardGame[4]) && (isFree(9))) //048 | 8
		return 9;
    else if((boardGame[0] == boardGame[8]) && (isFree(5))) //048 | 4
		return 5;
    else if((boardGame[4] == boardGame[8]) && (isFree(1))) //048 | 0
		return 1;
    else if((boardGame[1] == boardGame[4]) && (isFree(8))) //147 | 7
        return 8;
    else if((boardGame[1] == boardGame[7]) && (isFree(5))) //147 | 4
        return 5;
    else if((boardGame[4] == boardGame[7]) && (isFree(2))) //147 | 1
        return 2;
    else if((boardGame[2] == boardGame[5]) && (isFree(9))) //258 | 8
        return 9;
    else if((boardGame[2] == boardGame[8]) && (isFree(6))) //258 | 5
        return 6;
    else if((boardGame[5] == boardGame[8]) && (isFree(3))) //258 | 2
        return 3;
    else if((boardGame[3] == boardGame[4]) && (isFree(6))) //345 | 5
        return 6;
    else if((boardGame[3] == boardGame[5]) && (isFree(5))) //345 | 4
        return 5;
    else if((boardGame[4] == boardGame[5]) && (isFree(4))) //345 | 3
        return 4;
    else if((boardGame[6] == boardGame[7]) && (isFree(9))) //678 | 8
        return 9;
    else if((boardGame[6] == boardGame[8]) && (isFree(8))) //678 | 7
        return 8;
    else if((boardGame[8] == boardGame[7]) && (isFree(7))) //678 | 6
        return 7;
    else if((boardGame[2] == boardGame[4]) && (isFree(7))) //246 | 6
        return 7;
    else if((boardGame[2] == boardGame[6]) && (isFree(5))) //246 | 4
        return 5;
    else if((boardGame[6] == boardGame[4]) && (isFree(3))) //246 | 2
        return 3;
	else
        return -1;
}

//produce random number for computer turn
int TTT::randomPlay(){
    int temp;
    while(true){
        temp = rand() % 9 + 1;
        if(isFree(temp))
            break;
    }
    return temp;
}

//return true if the specific board is empty
bool TTT::isFree(int x){
    if(boardGame[x-1] != 'X' && boardGame[x-1] != 'O'){
        return true;
	}
    return false;
}

//asks user for their choice
int TTT::getTurn(){
    int number;
    cout << "Which number you want to put : ";
    cin >> number;
    return number;
}

//displays the board
void TTT::display(){
    cout << endl;
    cout << "       " << boardGame[0] << "  |  " << boardGame[1] << "  |  " << boardGame[2] << endl;
    cout << "     -----+-----+-----"  << endl;
    cout << "       " << boardGame[3] << "  |  " << boardGame[4] << "  |  " << boardGame[5] << endl;
    cout << "     -----+-----+-----"  << endl;
    cout << "       " << boardGame[6] << "  |  " << boardGame[7] << "  |  " << boardGame[8] << endl;
    cout << "     -----+-----+-----"  << endl;
    return;
}

//displays the rules
void TTT::showRules(){
    string slash = "////";
    string tripleTab = "\t\t\t";
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << slash << tripleTab << " Welcome to Constantine's Tic-Tac-Toe game. " << tripleTab << slash << endl;
    cout << slash << "\tRules: \t" << tripleTab << tripleTab << tripleTab <<  slash << endl;
    cout << slash << "\t(1) The object of Tic Tac Toe is to get three in a row. " << tripleTab << slash << endl;
    cout << slash << "\t(2) You play on a three by three game board.\t\t" << tripleTab << slash << endl;
    cout << slash << "\t(3) The first player is known as X and the second is O. " << tripleTab << slash << endl;
    cout << slash << "\t(4) Players alternate placing X and O on the game board." << tripleTab << slash << endl;
    cout << slash << "\t(6) Whoever gets three in a row first wins the game.\t" << tripleTab << slash << endl;
    cout << slash << "\t(5) If all nine squares are filled and no one has three in a row, it is a draw.\t" << slash << endl;
    cout << slash << "\t\t" << tripleTab << tripleTab << tripleTab << slash << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << endl << endl;
    return;
}

//check if the board is full
bool TTT::isFull(int count){
    if(count == 9)
        return true;
    return false;
}

//asks the user who wants to go first
char TTT::whoGoesFirst(){
	char goFirst;
    cout << "\nWho wants to go first? (X / O): ";
    cin >> goFirst;
    goFirst = toupper(goFirst);
    return goFirst;
}

//checks if there is a winner, if there is, returns true
bool TTT::isWinner(){
	//these codes check for a winner based on the first column
	if((boardGame[0] == boardGame[1]) && ((boardGame[0]) == (boardGame[2])))
		return true;
	else if( (boardGame[0] == boardGame[4]) && (boardGame[0]) == (boardGame[8]) )
		return true;
	else if( (boardGame[0]) == (boardGame[3]) && (boardGame[0]) == (boardGame[6]) )
		return true;
	//this code check for a winner based on the second column
	else if( (boardGame[1]) == (boardGame[4]) && (boardGame[1]) == (boardGame[7]))
		return true;
	//these code check for a winner based on the third column
	else if( (boardGame[2]) == (boardGame[5]) && (boardGame[2]) == (boardGame[8]) )
		return true;
	else if( (boardGame[2]) == (boardGame[4]) && (boardGame[2]) == (boardGame[6]) )
		return true;
	//this code check for a winner based on the second row
	else if( (boardGame[3]) == (boardGame[4]) && (boardGame[3]) == (boardGame[5]) )
		return true;
	//this code check for a winner based on the third row
	else if( (boardGame[6]) == (boardGame[7]) && (boardGame[6]) == (boardGame[8]) )
		return true;
	else
		return false;
}

//automatically switches player's turns
char TTT::switchTurn(char player){
	if(player == 'X')
		return 'O';
	else
		return 'X';
}

//takes user choice and changes the board based on player's symbol
void TTT::Go(int userChoice, char player){
    boardGame[userChoice-1] = player;
    return;
}

//clears the board
void TTT::reset(){
    boardGame[0] = '1';
    boardGame[1] = '2';
    boardGame[2] = '3';
    boardGame[3] = '4';
    boardGame[4] = '5';
    boardGame[5] = '6';
    boardGame[6] = '7';
    boardGame[7] = '8';
    boardGame[8] = '9';
    return;
}

//asks user if he/she wants to end the game
char TTT::exitGame(){
    char x;
    cout << endl << endl;
    cout << "Do you want to play again? Press E to exit the program: ";
    cin >> x;
    x = toupper(x);
    return x;
}
