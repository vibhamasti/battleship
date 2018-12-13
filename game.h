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
    std::fstream playerNames;   // file that stores player names
    bool isWon;
    Coord guessPos;
public:
    Game();
    void getPlayers();
    void checkFile(char *);     // TODO: define
    bool inPlay();              // TODO: define
    void updateScores();        // TODO: define
    void play();
};



#endif /* game_h */
