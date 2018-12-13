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
    std::fstream playerNames;                   // file that stores player names
    bool isWon;
public:
    Game();
    void getPlayers();
    void checkFile(char *);                     // TODO: define
    bool inPlay();                              // TODO: define
    void updateScores(Player, Player, Coord);   // TODO: define
    void play();
};



#endif /* game_h */
