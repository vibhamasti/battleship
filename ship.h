//
//  ship.h
//  Battleship
//


#ifndef ship_h
#define ship_h

#include "coord.h"



class Ship {
    int len;                    // length of a Ship
    char ori;                   // orientation
    Coord pos;                  // starting position
    
public:
    Ship();                     // constructor
    
    void setLen(int);           // sets the len of ship
    void input();               // inputs ori and pos
    
    int getLen();               // returns len
    Coord getPos();             // returns pos
    char getOri();              // returns ori
};

#endif /* ship_h */
