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
    p1HighScore = 0;
    p2HighScore = 0;
}

bool Game::inPlay() {
    return !isWon;
}

// to check data file for pname
int Game::checkFile(char *pname) {
    
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
        
	}	
	
	// if name does not exist 
	else {
        cout << "\nHello, " << currentPlayer.name << "! First time playing?\n";

		// add name to data file with high score 0
	    currentPlayer.score = 0;

        // open file
		playerFile.open("playerNames.dat", ios::binary | ios::app);
		playerFile.write((char*) &currentPlayer, sizeof(currentPlayer));
		playerFile.close();
	}

    // high score
    cout << "Your high score is: " << currentPlayer.score << "\n";

    return currentPlayer.score;
	
}

// save new high score
void Game::saveScore(char *pname, int pscore) {
    fstream playerFile;                 // file with all the player names
    playerData tempPlayer;
    int pos = 0;

    playerFile.open("playerNames.dat", ios::binary | ios::in | ios::out);

    // read every player in file
    while (playerFile.read((char *) &tempPlayer, sizeof(tempPlayer))) {

        // store position of file pointer (end of record)
        pos = playerFile.tellg();

        // if player name found
        if (strcmp(tempPlayer.name, pname) == 0) {
            tempPlayer.score = pscore;
            playerFile.seekg(pos - sizeof(tempPlayer), ios::beg);
            playerFile.write((char* ) &tempPlayer, sizeof(tempPlayer));
            break;
        }

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
    p1HighScore = checkFile(p1.getName());        
    
    // input details of player 1's ships
    p1.inputShips();
    
    // print player 1's map with ships
    cout << "\n\n" << p1.getName() << "'s map\n\n";
    p1.printFullMap();
    
    // TODO: clear screen

    // PLAYER 2

    // print player 2's empty map
    cout << "\n\n\nPlayer two\n";
    p2.printFullMap();
    
    
    cin.ignore();
    
    // input player 2's name
    p2.inputName();
    
    // checks database for player 2's name
    p2HighScore = checkFile(p2.getName());        
    
    // input details of player 2's ships
    p2.inputShips();
    
    // print player 2's map with ships
    cout << "\n\n" << p2.getName() << "'s map\n\n";
    p2.printFullMap();
    

    // TODO: clear screen
}

void Game::play() {
    Coord guessPos;
    
    //////////////
    // PLAYER 1 //
    //////////////

    // player 1 makes guess
    cout << p1.getName() << ": enter your guess:\n";
    
    guessPos.input();
    
    // checks for valid input and changes coord values in map
    guessPos = p2.getsHit(guessPos);
    
    // updates score
    updateScores(p1, p2, guessPos);
    

    // displays partial map of player 2
    cout << endl << p2.getName() << "'s map for " << p1.getName() << " to view:\n";
    p2.printGuessMap();
    
    // TODO: display scores of player 1
    
    // check if game is won (check p2's ships)
    if (p2.allShipsSunk()) {
        // player 1 has won
        cout << "\nCongratulations, " << p1.getName() << "!\n";
        cout << "You have won the game with " << p1.getScore() << " points\n";

        if (p1.getScore() > p1HighScore) {
            cout << "New high score!\n";
            saveScore(p1.getName(), p1.getScore());
        }

        isWon = true;
    }

    // TODO: clear screen
    

    //////////////
    // PLAYER 2 //
    //////////////

    // player 2 makes guess
    cout << p2.getName() << ": enter your guess:\n";
    guessPos.input();

    // checks for valid input and changes coord values in map
    guessPos = p1.getsHit(guessPos);
    
     // updates score
    updateScores(p2, p1, guessPos);


    // displays partial map of player 1
    cout << endl << p1.getName() << "'s map for " << p2.getName() << " to view:\n";
    p1.printGuessMap();

    
    // TODO: display scores of player 2

    // check if game is won (check all of p1's ships)
    if (p1.allShipsSunk()) {

        // player 2 has won
        cout << "\nCongratulations, " << p2.getName() << "!\n";
        cout << "You have won the game with " << p2.getScore() << " points\n";

        if (p2.getScore() > p2HighScore) {
            cout << "New high score!\n";
            saveScore(p2.getName(), p2.getScore());
        }

        isWon = true;
    }
    
    // TODO: clear screen
    
}
