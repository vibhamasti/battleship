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
    
    // print rules of the game
    battleship.printRules();

    // input two players' details
    battleship.inputPlayers();
    
    // play the game while no one has one
    while (battleship.inPlay()) {
        battleship.play();   
    }
    
    // TODO: un-comment
    // _getch();
    return 0;
}

