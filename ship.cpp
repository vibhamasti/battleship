//
//  ship.cpp
//  Battleship
//


#include "ship.h"

#include <iostream>

using namespace std;

Ship::Ship() {
    len = 0;
}

int Ship::getLen() {
    return len;
}

Coord Ship::getPos() {
    return pos;
}

char Ship::getOri() {
    return ori;
}

// sets length of each ship
void Ship::setLen(int l) {
    len = l;
}

// input ship details
void Ship::input() {
    
    // input position (coordinates)
    cout << "Starting position (coordinates):\n";
    pos.input();
    
    // input orientation
    cout << "Orientation (v/h): ";
    cin >> ori;
    
    while (ori != 'h' && ori != 'v') {
        cout << "Please enter 'v' or 'h' only: ";
        cin >> ori;
    }
    
}

