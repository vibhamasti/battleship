//
//  main.cpp
//  Battleship



// #include "stdafx.h"
#include <iostream>
// #include <conio.h>

#include "game.cpp"

using namespace std;


int main() {
    // rules
    
    Game battleship;
    
    // two player game
    battleship.inputPlayers();
    
    while (battleship.inPlay()) {
        battleship.play();
        
    }
    
    // TODO: un-comment
    // _getch();
    return 0;
}

