//
//  game.h
//  Battleship
//

#ifndef game_h
#define game_h

#include "player.cpp"
#include <fstream>
#include <iostream>



class Game {
    Player p1, p2;
    std::fstream playerNames;                       // file that stores player names
    bool hasEnded;
public:
    Game();
    
    // game initialise functions
    void inputPlayers();
    void printRules();
    void inputPlayerData(Player&, Player&);         // input player name and ships
    void checkFile(Player&);                        // checks file for name and minimum turns

    // game play functions
    void play();                                    // play the game by playing multiple rounds
    void playRound(Player&, Player&);               // play one round of hitting/scoring/printing
    bool inPlay();
    void saveBestTurns(char *, int);                // save best number of turns onto file      
};



#endif /* game_h */
