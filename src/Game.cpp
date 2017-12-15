#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

//starts the game
void Game::startGame(){
    do {
        reset(); //reset the board
        showRules(); //display the rules to the user
        userChoice = askUser(); //asks user what type of game he/she wants to play

		//human vs human
        if(userChoice == 1)
            HumanVSHuman();

       	//human vs computer code
	    else if(userChoice == 2)
           	HumanVSMachine();

        //computer vs computer
		else if(userChoice == 3)
            MachineVSMachine();

        //in case user input another number
        else
            cout << endl << "!You input the wrong number!";

        stopGame = exitGame();
        cout << endl << "\t\t\t------------------------------------------" << endl;
    } while(stopGame != 'E');
}

//executes human vs human game
void Game::HumanVSHuman(){
    count = 0;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl << "You choose 1. \n" << "Good luck have fun! " << endl;
    player = whoGoesFirst(); //asks user who wants to go first

    //keeps playing until we find the winner
    //or until the board is full
    while(!isWinner()){
        display();
        cout << "\nUser " << player << " turns: ";
        userChoice = getTurn(); //ask user for his move
        Go(userChoice, player);
        player = switchTurn(player); //change the player turns
        count++;
        if(isFull(count))
            break;
    }
    display();
    cout << "\nThe game ends" << endl;

    if(isWinner()){
        player = switchTurn(player);
        cout << "User " << player << " wins! CONGRATULATIONS";
    } else {
        cout << "It is a draw. Better luck next time! ";
    }
}

//executes human vs machine game
void Game::HumanVSMachine(){
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl << "You choose 2. \n" << "So, you think you can beat my machine? " << endl;
    cout << "Well, let's see what you got!" << endl;
    cout << "Choose your mode: " << endl;
    cout << "(1) Easy. " << endl;
    cout << "(2) Medium. " << endl;
    cout << "(3) Hard. " << endl;
    cin >> userChoice;

    if(userChoice == 1){
        cout << "Do you want to go first or second? ENTER 1 or 2." << endl;
        cin >> userChoice;
        if(userChoice == 1){
          HuVSMaHumanFirst();
        }
        else if(userChoice == 2){
          HuVSMaMachineFirst();
        }
    } else if(userChoice == 2){
        MediumDifficulty();
    } else if(userChoice == 3){
        PerfectCode();
    }
}

//executes human vs machine first, human plays first
void Game::HuVSMaHumanFirst(){
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
	player = 'X';
	count = 0;
    cout << endl << "You are player X" << endl;
    display();

    while(!isWinner()){
        cout << endl << "Please make your move" << endl;
        userChoice = getTurn();
        Go(userChoice, player);
        display();
        count++;

        if(isWinner()) break;
        if(isFull(count)) break;

        player = switchTurn(player);
        cout << endl << "Now it's computer turn:" << endl;
        int temp = 0;
        while(true){
            temp = rand() % 9 + 1;
            if(isFree(temp))
                break;
        }
        Go(temp,player);
        display();
        if(isWinner()){
            break;
        }
        player = switchTurn(player);
        count++;

        if(isFull(count)) break;
    }
    cout << "\nThe game ends" << endl;

    if(isWinner()){
        cout << "User " << player << " wins! CONGRATULATIONS";
    } else {
        cout << "It is a draw. Better luck next time! ";
    }
}

//executes human vs machine first, machine plays first
void Game::HuVSMaMachineFirst(){
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    player = 'X';
    count = 0;
    cout << endl << "Computer is player X" << endl;
    display();

    while(!isWinner()){
        cout << endl << "Computer's turn:" << endl;
        int temp = 0;
        while(true){
            temp = rand() % 9 + 1; //generating random number
            if(isFree(temp)) //checking if the array with that random number empty. If it is empty, break
                break;
        }
        cout << "Computer choose " << temp << endl;
        Go(temp,player);
        display();

        if(isWinner())
            break;
        if(isFull(count)) //should check if the board is full
            break;

        player = switchTurn(player);

        cout << endl << "Please make your move" << endl;
        userChoice = getTurn();
        Go(userChoice, player);
        display();
        count++;

        if(isWinner()){
            break;
        }

        player = switchTurn(player);
        count++;

        if(isFull(count)) //should check if the board is full
            break;
    }
        cout << "\nThe game ends" << endl;

        if(isWinner()){
            cout << "User " << player << " wins! CONGRATULATIONS";
        } else {
            cout << "It is a draw. Better luck next time! ";
        }
}

//medium difficulty where machine only moves to prevent player from winning
void Game::MediumDifficulty(){
    player = 'X';
	count = 0;
	cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl << "You are player X" << endl;
    display();
    while(!isWinner()){
        cout << endl << "Please make your move" << endl;
        userChoice = getTurn();
        Go(userChoice, player);
        display();
        count++;
        if(isWinner()) break;
        if(isFull(count)) break;
        int temp = 0;

        //will check if the user almost win or not
        if(possWin(player) != -1){
            temp = possWin(player);
            cout << "Computer choose " << temp << endl;
            player = switchTurn(player);
            Go(temp,player);
            player = switchTurn(player);
            display();
        } else if (possWin(player) == -1){
            while(true){
            temp = rand() % 9 + 1; //generating random number
            if(isFree(temp)){ //checking if the array with that random number empty. If it is empty, break
                cout << "Computer choose " << temp << endl;
                player = switchTurn(player);
                Go(temp,player);
                display();
                player = switchTurn(player);
                break;
                }
            }
        }

        count++;
        if(isWinner()) break;
        if(isFull(count)) break;
    }
    cout << "\nThe game ends" << endl;

    if(isWinner())
        cout << "User " << player << " wins! CONGRATULATIONS";
     else
        cout << "It is a draw. Better luck next time! ";
};

//perfect code that machine never lose
void Game::PerfectCode(){
    player = 'X';
	count = 0;
	cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl << "You are player X" << endl;
    display();
    while(!isWinner()){
        cout << endl << "Please make your move" << endl;
        userChoice = getTurn();
        Go(userChoice, player);
        display();
        count++;
        if(isWinner()) break;
        if(isFull(count)) break;
        int temp = 0;

        //will check if the user almost win or not
        if(possWin(player) != -1){
            temp = possWin(player);
        } else {
        		int i = 0;
        		int moves[] = {1, 5, 3, 7, 9, 2, 4, 6, 8};
        		for(int j = 0; j < 9; j++){
        			int move = moves[j];
        			if(isFree(move)){
        				temp = move;
        				break;
        			}
        		}
        }
        player = switchTurn(player);
        cout << endl << "Now it's computer turn:" << endl;
        Go(temp,player);
        display();
        if(isWinner()) break;

        player = switchTurn(player);
        count++;

        if(isFull(count)) break;
    }
    cout << "\nThe game ends" << endl;

    if(isWinner())
        cout << "User " << player << " wins! CONGRATULATIONS";
     else
        cout << "It is a draw. Better luck next time! ";
};

//executes machine vs machine game
void Game::MachineVSMachine(){
    count = 0;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl << "You choose 3. \n" << "Now, enjoy watching this silly machine trying to play against each other! " << endl;
    player = 'X';
    int computerMove; //saves computer move
    while(!isWinner()){
        cout << "\nComputer " << player << " turns: " << endl;
        computerMove = randomPlay();
        Go(computerMove,player);
        player = switchTurn(player); //change the characters turns
        display();
        count++;
        if(isFull(count))
            break;
    }
    cout << "\nThe game ends" << endl;
    if(isWinner()){
        player = switchTurn(player);
        cout << "Computer " << player << " wins! CONGRATULATIONS";
    } else {
        cout << "It is a draw. Dang it, stupid computer! ";
    }
}
