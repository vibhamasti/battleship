//
//  game.cpp
//  Battleship
//

// #include "stdafx.h"

#include "game.h"
#include <fstream>
#include <iostream>

using namespace std;

// constructor (resets game)
Game::Game() {
    isWon = false;
}

bool Game::inPlay() {
    return !isWon;
}

// to check data file for pname
void Game::checkFile(char *pname) {
    
    bool isFound = false;                   // variable to state if player name exists
    fstream playerFile;                     // file that stores all player names	
	playerData currentPlayer;               // variable that contains name and score of player
	playerData tempPlayer;                  // variable that reads player info from file
	
	// copies pnname to currentPlayer
	strcpy(currentPlayer.name,pname);

	// open file
	playerFile.open("playerNames.dat", ios::binary | ios::in);

    // search playerFile for currentPlayer
	while (playerFile.read((char*) &tempPlayer, sizeof(tempPlayer))) {
        
        // if currentPlayer's name exists
        if (strcmp(tempPlayer.name, currentPlayer.name) == 0) {
            currentPlayer = tempPlayer;
            isFound = true;
            break;
        }
	
	}

    // close file
	playerFile.close();
	
	
	// if name name exists
	if (isFound) {	
		// display old high score
		cout << "\nWelcome back, " << currentPlayer.name << "!\n";
        cout << "Your high score is: " << currentPlayer.score << "\n";

	}	
	
	// if name does not exist 
	else {
        cout << "\nHello, " << currentPlayer.name << "! First time playing?\n";
		cout << "Your score is: 0\n";

		// add name to data file with high score 0
	    currentPlayer.score = 0;

        // open file
		playerFile.open("playerNames.dat", ios::binary | ios::app);
		playerFile.write((char*) &currentPlayer, sizeof(currentPlayer));
		playerFile.close();
	}


	
}

// function to update scores of player madeHit
void Game::updateScores(Player madeHit, Player gotHit, Coord guessPos) {
    
	// madeHit is the player whose round is being played
    // gotHit is the current player's opponent
	// TODO: finish function

}

void Game::getPlayers() {
    // PLAYER 1
    
    // print player 1's empty map
    cout << "\n\n\nPlayer one\n";
    p1.printFullMap();
    
    // input player 1's name
    p1.inputName();
    
    // checks database for player 1's name
    checkFile(p1.getName());        
    
    // input details of player 1's ships
    p1.inputShips();
    
    // print player 1's map with ships
    cout << "\n\n" << p1.getName() << "'s map\n\n";
    p1.printFullMap();
    
    // PLAYER 2

    // print player 2's empty map
    cout << "\n\n\nPlayer two\n";
    p2.printFullMap();
    
    
    cin.ignore();
    
    // input player 2's name
    p2.inputName();
    
    // checks database for player 2's name
    checkFile(p2.getName());        
    
    // input details of player 2's ships
    p2.inputShips();
    
    // print player 2's map with ships
    cout << "\n\n" << p2.getName() << "'s map\n\n";
    p2.printFullMap();
    
}

void Game::play() {
    Coord guessPos;
    
    // PLAYER 1

    // player 1 makes guess
    cout << p1.getName() << ": enter your guess:\n";
    
    guessPos.input();
    
    // checks for valid input and changes coord values in map
    p2.getsHit(guessPos);
    
    // updates score
    updateScores(p1, p2, guessPos);
    
    cout << endl << p2.getName() << "'s map for " << p1.getName() << " to view:\n";
    
    // TODO: displays partial map and not entire map
    // use GuessCoord values for this
    p2.printFullMap();
    
    // TODO: display scores of player 1
    
    // TODO: check if game is won
    
    // TODO: clear screen
    

    // PLAYER 2

    // player 2 makes guess
    cout << p2.getName() << ": enter your guess:\n";
    guessPos.input();
    // checks for valid input and changes coord values in map
    p1.getsHit(guessPos);
    
    // TODO: updates score
    updateScores(p2, p1, guessPos);

    cout << endl << p1.getName() << "'s map for " << p2.getName() << " to view:\n";
    
    // TODO: displays partial map
    // use GuessCoord values for this
    p1.printFullMap();
    
    // TODO: display scores of player 2

    // TODO: check if game is won
    
    // TODO: clear screen
    
}
