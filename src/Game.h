#ifndef GAME_H
#define GAME_H
#include "TTT.h"

class Game: public TTT{
    public:
        void startGame(); //starts the game
        void HumanVSHuman(); //human vs human game
        void MachineVSMachine(); //machine vs machine game
        void HumanVSMachine(); //human vs machine game
        void HuVSMaHumanFirst(); //human vs machine game where human play first
        void HuVSMaMachineFirst(); //human vs machine game where machine play first
        void PerfectCode(); //human vs machine game with hard difficulty
        void MediumDifficulty(); //human vs machine game with medium difficulty
};

#endif // GAME_H
