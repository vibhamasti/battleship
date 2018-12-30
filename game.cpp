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
    hasEnded = false;
}

bool Game::inPlay() {
    return !hasEnded;
}

void Game::printRules() {
    char ch;
    cout << "\n\nWelcome to Battleship\n\n";

    cout << "This is a two-player game of battleship.\n";
    cout << "Each player will enter the coordinates of their\n";
    cout << "ships one-by-one and orient them to their wish.\n\n";

    cout << "The objective of the game is to try and guess the\n";
    cout << "location of your opponent's ships by entering coordinates.\n";
    cout << "If a guess is at the loaction of a ship, it is called a\n";
    cout << "hit. If the guess is a water tile, it is called a miss.\n";
    cout << "If all of the coordinates of one ship have been hit,\n";
    cout << "the ship is said to have been sunk\n";


    cout << "The winner of the game is the one who has sunk their\n";
    cout << "opponent's ships in the least number of guesses.\n\n";

    cout << "Game board symbols:\n";
    cout << "0 - empty tile\n";
    cout << "1 - ship present in tile\n";
    cout << "2 - ship has been hit\n";
    cout << "3 - ship has been sunk\n";
    cout << "4 - water has been hit (miss)\n";

    cout << "\nScoring is based on number of shots made and\n";
    cout << "percentage of success.\n\n";

    cout << "Good luck!\n\n";

    cout << "Are you ready to play? (press enter)";
    while(cin.get(ch)) {
        if (ch == '\n') break;
    };
}

// to check data file for pname
void Game::checkFile(Player &currentPlayer) {
    
    bool isFound = false;                   // variable to state if player name exists
    fstream playerFile;                     // file that stores all player names	
	
	playerData tempData;                    // variable that reads player info from file
	
	// open file
	playerFile.open("playerNames.dat", ios::binary | ios::in);

    // search playerFile for currentPlayer
	while (playerFile.read((char*) &tempData, sizeof(tempData))) {
        
        // if currentPlayer's name exists on file
        if (strcmp(tempData.name, currentPlayer.getName()) == 0) {
            // copy saved high score onto currentPlayer
            currentPlayer.setHighScore(tempData.score);
            isFound = true;
            break;
        }
	
	}

    // close file
	playerFile.close();
	
	
	// if currentPlayer's name exists
	if (isFound) {	
		// display old high score
		cout << "\nWelcome back, " << currentPlayer.getName() << "!\n";
	}	
	
	// if name does not exist 
	else {
        cout << "\nHello, " << currentPlayer.getName() << "! First time playing?\n";

		// set player's high score to 
	    currentPlayer.setHighScore(0);

        // store currentPlayer's data onto temp variable
        strcpy(tempData.name, currentPlayer.getName());
        tempData.score = currentPlayer.getHighScore();

        // open file
		playerFile.open("playerNames.dat", ios::binary | ios::app);
		playerFile.write((char*) &tempData, sizeof(tempData));
		playerFile.close();
	}

    // high score
    cout << "Your high score is: " << currentPlayer.getHighScore() << "\n";

	
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

    // close the file
    playerFile.close();

}


// function to update scores of player madeHit
void Game::updateScores(Player &madeHit, Player &gotHit, Coord &guessPos) {
    
	// madeHit is the player whose round is being played
    switch (gotHit.coordValue(guessPos)) {
        // coordniate cannot empty
        case MapCoord::shipExist: {

        }
        case MapCoord::shipHit: {

        }
        case MapCoord::shipMiss: {

        }
        case MapCoord::shipSunk: {

        }
    }
    // gotHit is the current player's opponent
	// TODO: finish function

}

// input's single player's data
void Game::inputPlayerData(Player &currentPlayer, Player &other) {

    // print currentPlayer's empty map
    currentPlayer.printFullMap();
    
    // input currentPlayer's name (ensure it is unique)
    
    currentPlayer.inputName();
    
    while (!strcmp(currentPlayer.getName(), other.getName())) {
        cout << currentPlayer.getName() << " is already playing.\n";
        currentPlayer.inputName();
    }
    

    
    // checks database for currentPlayer's name and high score
    checkFile(currentPlayer);        
    
    // input details of currentPlayer's ships
    currentPlayer.inputShips();
    
    // print currentPlayer's map with ships
    cout << "\n\n" << currentPlayer.getName() << "'s map\n\n";
    currentPlayer.printFullMap();
    
    

    // TODO: clear screen

}

// inputs data of two players
void Game::inputPlayers() {
    char ch;
    // PLAYER 1

    cout << "\n\n\nPlayer one\n";
    inputPlayerData(p1, p2);

    cin.ignore();

    // waiting for player 2
    // wait for player 2
    cout << "Call player 2: (press enter)";
    while(cin.get(ch)) {
        if (ch == '\n') break;
    };

    // PLAYER 2

    cout << "\n\n\nPlayer two\n";
    inputPlayerData(p2, p1); 

}

// TODO: check TODOs
void Game::playRound(Player &madeHit, Player &gotHit) {
    Coord guessPos;

    // TODO: clear
    cout << endl << endl;
    cout << madeHit.getName() << ": " << gotHit.getName() << "'s current map\n\n";

    // print current guess map gotHit
    gotHit.printGuessMap();

    cout << endl << endl;

    // madeHit makes guess by entering coordinates
    cout << madeHit.getName() << ": enter your guess:\n";
    guessPos.input();
    

    // gotHit gets hit at valid coordinate
    guessPos = gotHit.getsHit(guessPos);
    
    // TODO: updates scores of madeHit and gotHit
    updateScores(madeHit, gotHit, guessPos);
    

    // displays partial map of gotHit so madeHit can see it
    cout << endl << gotHit.getName() << "'s map for " << madeHit.getName() << " to view:\n";
    gotHit.printGuessMap();
    
    // TODO: display scores of madeHit
    
    // check if game is won (check gotHit's ships)
    if (gotHit.allShipsSunk()) {
        
        // makesHit has won
        cout << "\nCongratulations, " << madeHit.getName() << "!\n";
        cout << "You have won the game with " << madeHit.getScore() << " points\n";

        // update high score onto data file
        if (madeHit.getScore() > madeHit.getHighScore()) {
            cout << "New high score!\n";
            saveScore(madeHit.getName(), madeHit.getScore());
        }

        hasEnded = true;
    }

    // TODO: clear screen
}

// play the game (two rounds)
void Game::play() {
    char ch;
    
    //////////////
    // PLAYER 1 //
    //////////////

    cin.ignore();

    // wait for player 1
    cout << "\nCall " << p1.getName() << ": (press enter)";
    while(cin.get(ch)) {
        if (ch == '\n') break;
    };

    playRound(p1, p2);

    // check if game has ended
    if (hasEnded) {
        return;
    }


    //////////////
    // PLAYER 2 //
    //////////////

    cin.ignore();
    
    // wait for player 2
    cout << "\nCall " << p2.getName() << ": (press enter)";
    while(cin.get(ch)) {
        if (ch == '\n') break;
    };

    playRound(p2, p1);

    // check if game has ended
    if (hasEnded) {
        return;
    }

    

    // TODO: increase number of shots fired
    
}
