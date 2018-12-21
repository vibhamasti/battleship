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
    
    void saveScore(char *, int);                // save high score onto file                  
                                  
    void updateScores(Player, Player, Coord);   // TODO: define
    
    // game initialise functions
    void inputPlayers();
    void inputPlayerData(Player);
    void checkFile(Player);                      // checks file for name and high score

    // game play functions
    void play();                                // play the game by playing multiple rounds
    void playRound(Player, Player);             // play one round of hitting/scoring/printing
    bool inPlay();
};



#endif /* game_h */
