//
//  game.cpp
//  Battleship
//


#include "game.h"

using namespace std;

// constructor (resets game)
Game::Game() {
    isWon = false;
}

bool Game::inPlay() {
    return !isWon;
}

// TODO: function definition
void Game::checkFile(char *pname) {
    // check data file for p1
    // if p1 exists (username)
    // display old high score
    // ask them to beat it
    
    // if does not exist
    // ask if first time playing
    // add name to data file with high score 0
    // display high score
}

void Game::getPlayers() {
    // player 1
    
    // print player 1's empty map
    cout << "\n\n\nPlayer one\n";
    p1.printFullMap();
    
    // input player 1's name
    p1.inputName();
    
    // check data file for the name and add new
    // TODO: display message such as 'welcome back'
    // TODO: display high score
    checkFile(p1.getName());        // TODO: function definition
    
    // input details of player 1's ships
    p1.inputShips();
    
    // print player 1's map with ships
    cout << "\n\n" << p1.getName() << "'s map\n\n";
    p1.printFullMap();
    
    // player 2
    
    // print player 2's empty map
    cout << "\n\n\nPlayer two\n";
    p2.printFullMap();
    
    
    cin.ignore();
    
    // input player 2's name
    p2.inputName();
    
    // check data file for the name and add new
    // TODO: display message such as 'welcome back'
    // TODO: display high score
    checkFile(p2.getName());        // TODO: function definition
    
    // input details of player 2's ships
    p2.inputShips();
    
    // print player 2's map with ships
    cout << "\n\n" << p2.getName() << "'s map\n\n";
    p2.printFullMap();
    
}

void Game::play() {
    
    // player 1 makes guess
    cout << p1.getName() << ": enter your guess:\n";
    
    guessPos.input();
    
    // checks for valid input and changes coord values in map
    p2.getsHit(guessPos);
    
    // TODO: updates score
    // updateScores()
    
    cout << endl << p2.getName() << "'s map for " << p1.getName() << " to view:\n";
    
    // TODO: displays partial map
    p2.printFullMap();
    
    // displays scores
    
    // game is won?
    
    // TODO: clear screen
    
    // player 2 makes guess
    cout << p2.getName() << ": enter your guess:\n";
    guessPos.input();
    // checks for valid input and changes coord values in map
    p1.getsHit(guessPos);
    
    // TODO: updates score
    // updateScores()

    cout << endl << p1.getName() << "'s map for " << p2.getName() << " to view:\n";
    
    // TODO: displays partial map
    p1.printFullMap();
    
    // displays scores
    // game is won?
    
    
    
}
