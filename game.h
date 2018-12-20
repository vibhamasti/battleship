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
    int p1HighScore, p2HighScore;               // high scores of two players
    std::fstream playerNames;                   // file that stores player names
    bool isWon;
public:
    Game();
    void getPlayers();
    int checkFile(char *);                      // checks file for high score
    void saveScore(char *, int);                // save high score onto file                  
    bool inPlay();                              
    void updateScores(Player, Player, Coord);   // TODO: define
    void play();
};



#endif /* game_h */
