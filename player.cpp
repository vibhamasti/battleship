//
//  player.cpp
//  Battleship


#include "player.h"
#include <iostream>

using namespace std;


// constructor
Player::Player() {
    pData.score = 0;
    highScore = 0;

    // set the length of each ship (starting size 2)
    for (int i = 0; i <= NO_OF_SHIPS; ++i) {
        ships[i].setLen(i + 2);
    }
    
    // inintialise map's coordinates to empty
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            shipMap[i][j] = MapCoord::empty;
        }
    }
    
}

// sets high score
void Player::setHighScore(int hs) {
    highScore = hs;
}


// increase score
void Player::increaseScore(int n) {
    pData.score += n;
}

// returns name of player
char* Player::getName() {
    return pData.name;
}

// returns player score
int Player::getScore() {
    return pData.score;
}

// returns player high score
int Player::getHighScore() {
    return highScore;
}

// if ship lies within map and in empty coordinates
ShipCoord Player::getStatus(Ship testShip) {
    // if the ship will exit the map
    if (!inMap(testShip)) {
        return ShipCoord::outOfBounds;
    }
    
    // if another ship already exists
    if (!mapFree(testShip)) {
        return ShipCoord::occu;
    }
    
    // if coordinates entered are valid
    return ShipCoord::valid;
}

// returns a coordinate value (shipExist, shipSunk etc) 
MapCoord Player::coordValue(Coord guess) {
    return shipMap[guess.y][guess.x];
}


// check if input coordinates of ship lie within the map
bool Player::inMap(Ship testShip) {
    if (testShip.getOri() == 'h' && testShip.getPos().x + testShip.getLen() > MAP_SIZE) {
        return false;
    }
    if (testShip.getOri() == 'v' && testShip.getPos().y + testShip.getLen() > MAP_SIZE) {
        return false;
    }
    return true;
}

// checks if the coordinates for testShip
// to occupy are free to be used
bool Player::mapFree(Ship testShip) {
    // if the testShip is horizontally oriented
    if (testShip.getOri() == 'h') {
        // loops through all the coordinates
        // and checks if all are empty
        for (int i = testShip.getPos().x; i < (testShip.getPos().x + testShip.getLen()); ++i) {
            if (shipMap[testShip.getPos().y][i] != MapCoord::empty) {
                return false;
            }
        }
    }
    // if the testShip is vertically oriented
    else {
        // loops through all the coordinates
        // and checks if all are empty
        for (int i = testShip.getPos().y; i < (testShip.getPos().y + testShip.getLen()); ++i) {
            if (shipMap[i][testShip.getPos().x] != MapCoord::empty) {
                return false;
            }
        }
    }
    return true;
}

// checks if the guessed coordinates lie within the map
// or have been guessed already (uses Coord)
GuessCoord Player::guessValidity(Coord guess) {
    if (guess.x >= MAP_SIZE || guess.y >= MAP_SIZE) {
        return GuessCoord::outOfBounds;
    }
    // if coordinate not empty and not shipExist
    if (shipMap[guess.y][guess.x] != MapCoord::empty && shipMap[guess.y][guess.x] != MapCoord::shipExist) {
        return GuessCoord::guessed;
    }
    return GuessCoord::notYetGuessed;
}


// draws testShip onto the shipMap
void Player::drawShip(Ship testShip) {
    // if testShip is horizonally oriented
    if (testShip.getOri() == 'h') {
        // i is the changing x coordinate
        for (int i = testShip.getPos().x; i < testShip.getPos().x + testShip.getLen(); i++) {
            // changes empty to shipExist
            shipMap[testShip.getPos().y][i] = MapCoord::shipExist;
        }
        
    }
    // if testShip is vertically oriented
    else {
        // i is the changing y coordinate
        for (int i = testShip.getPos().y; i < testShip.getPos().y + testShip.getLen(); i++) {
            // changes empty to shipExist
            shipMap[i][testShip.getPos().x] = MapCoord::shipExist;
        }
    }
}

// input the player name
void Player::inputName() {
    cout << "\nEnter player name: ";
    cin >> pData.name;
}


// inputs the details of a player
void Player::inputShips() {
    // i is the index of the ship
    for (int i = 0; i < NO_OF_SHIPS; ++i) {
        cout << "\nDetails of ship " << i + 1 << " (length: " << ships[i].getLen() << " units)" << endl;
        
        // input the details of the i'th ship
        ships[i].input();
        
        
        while (getStatus(ships[i]) != ShipCoord::valid) {
            switch (getStatus(ships[i])) {
                    // if ship out of bounds
                case ShipCoord::outOfBounds: {
                    cout << "\nShip entered will not lie on the map.\n";
                    break;
                }
                    // if position already occupied by ship
                case ShipCoord::occu: {
                    cout << "\nPosition already occupied by another ship.\n";
                    break;
                }
                default: {
                    // will never execute
                    break;
                }
            }
            cout << "Re-enter coordinates:\n";
            ships[i].input();
            
        }
        
        
        // updates the ship map
        drawShip(ships[i]);
        
        cout << "\n\nUpdated map:\n\n";
        // prints map
        printFullMap();
        
    }
}

// prints the full map
void Player::printFullMap() {
    // prints x coordinates in a horizontal line
    cout << "\n   ";
    for (int j = 0; j < MAP_SIZE; ++j) {
        cout << j << " ";
        
    }
    cout << endl << endl;
    
    // prints y coordinates in a vertical line
    for (int i = 0; i < MAP_SIZE; i++) {
        cout << i << "  ";
        for (int j = 0; j < MAP_SIZE; j++) {
            cout << (int) shipMap[i][j] << " ";
        }
        cout << endl;
    }
}


// prints only the tiles that have been guessed
void Player::printGuessMap() {

    // prints x coordinates in a horizontal line
    cout << "\n   ";
    for (int j = 0; j < MAP_SIZE; ++j) {
        cout << j << " ";
        
    }
    cout << endl << endl;
    
    // prints y coordinates in a vertical line
    for (int i = 0; i < MAP_SIZE; i++) {
        cout << i << "  ";
        for (int j = 0; j < MAP_SIZE; j++) {
            // check guess validity
            if (guessValidity(Coord(j, i)) == GuessCoord::guessed) {
                cout << (int) shipMap[i][j] << " ";
            }
            else {
                cout << "X" << " ";
            }
        }
        cout << endl;
    }

}

// check if a ship has been sunk
bool Player::isSunk(Ship testShip) {
    
    if (testShip.getOri() == 'h') {
        for (int i = testShip.getPos().x; i < testShip.getPos().x + testShip.getLen(); i++) {
            if (shipMap[testShip.getPos().y][i] != MapCoord::shipHit && shipMap[testShip.getPos().y][i] != MapCoord::shipSunk)
                return false; 
        }
        return true;
    }
    
    else {
        for(int i = testShip.getPos().y; i < testShip.getPos().y + testShip.getLen(); i++){
            if (shipMap[i][testShip.getPos().x] != MapCoord::shipHit && shipMap[i][testShip.getPos().x] != MapCoord::shipSunk)
                return false;
        }
        return true;
    }
    
}

// sink a ship (updates all MapCoord values to shipSunk)
void Player::sink(Ship testShip) {
    if (testShip.getOri() == 'h') {
        for (int i = testShip.getPos().x; i < testShip.getPos().x + testShip.getLen(); i++) {
            shipMap[testShip.getPos().y][i] = MapCoord::shipSunk;
        }
    }
    
    else if (testShip.getOri() == 'v') {
        for (int i = testShip.getPos().y; i < testShip.getPos().y + testShip.getLen(); i++) {
            shipMap[i][testShip.getPos().x] = MapCoord::shipSunk;
        }
        
    }
}

// check if all ships have been sunk
bool Player::allShipsSunk() {
    for (int i = 0; i < NO_OF_SHIPS; ++i) {
        if (!isSunk(ships[i])) {
            return false;
        }
    }
    return true;
}


// player inputs a coordinate pair
Coord Player::getsHit(Coord guess) {
    
    // if the coordinates have already been hit/lie out of bounds
    while (guessValidity(guess) != GuessCoord::notYetGuessed) {
        // switch case for type of guess
        switch (guessValidity(guess)) {
            case GuessCoord::outOfBounds: {
                // coordinates are out of bounds
                cout << "Please enter coordinates from 0 to " << MAP_SIZE - 1 << ":\n";
                guess.input();
                break;
            }
            case GuessCoord::guessed: {
                // coordinates have already been guessed before
                cout << "(" << guess.x << ", " << guess.y << ") has already been played. Please enter new coordinates:\n";
                guess.input();
                break;
            }
        } // end of switch
    }
    
    // if a ship exists at the guessed location
    if (shipMap[guess.y][guess.x] == MapCoord::shipExist) {
        // a ship has been hit
        shipMap[guess.y][guess.x] = MapCoord::shipHit;
    }
    else {
        // the coordinate was a miss
        shipMap[guess.y][guess.x] = MapCoord::shipMiss;
    }
    
    // check if a ship has been sunk
    for (int i = 0; i < NO_OF_SHIPS; ++i) {
        // check if a ship should be sunk
        if (isSunk(ships[i])) {
            // sink the ship by changing all the map values
            sink(ships[i]);
        }
        
    }
    return guess;
}
