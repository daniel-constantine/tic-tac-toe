#ifndef TTT_H
#define TTT_H

class TTT {
    public:
        TTT(); //default constructor
        void reset(); //clears the board
        void showRules(); //displays the rules
        void display(); //display the board
        void Go(int x, char y); //takes an integer and changes the board based on player's symbol
        char whoGoesFirst(); //asks the user who wants to go first
        char switchTurn(char ); //automatically switches player's turns
        char exitGame(); //asks the user to exit the program
        int getTurn(); //asks the user where do they want to put the next X / O
        int randomPlay(); //return random number for computer movement
        int askUser(); //asks user what kind of game he/she wants
        int possWin(char ); //returns the position of player's possible win if the user one step away from victory
        bool isWinner(); //returns true if there is a winner
        bool isFull(int x); //returns true if the board is full and false if there is a space
        bool isFree(int x); //returns true if the board is free

    protected:
        char boardGame[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //this is the board game
        char player; //keep detail on character being used X or O
        char stopGame; //variable to contain character if user wants to exit
        int userChoice = 0; //to keep track of what the user's input
        int count = 0; //to keep track of how many board left

};

#endif // TTT_H
