//
//  game.h
//  Battleship
//

#ifndef game_h
#define game_h

#include "player.cpp"
#include <fstream>
#include <iostream>


// TODO: map for scores

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
    void checkFile(Player&);                        // checks file for name and high score
    bool nameExists(char*);                         // checks if player name exists

    // game play functions
    void play();                                    // play the game by playing multiple rounds
    void playRound(Player&, Player&);               // play one round of hitting/scoring/printing
    void updateScores(Player&, Player&, Coord&);    // TODO: define
    bool inPlay();
    void saveScore(char *, int);                    // save high score onto file      
};



#endif /* game_h */
