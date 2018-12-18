//
//  player.h
//  Battleship
//

#ifndef player_h
#define player_h
#include "ship.cpp"
#define NO_OF_SHIPS 5
#define MAP_SIZE 10
#define STR_LEN 20
// validity of coordinates for a ship
enum class ShipCoord {
    outOfBounds,                                // outside the map
    occu,                                       // occupied by other ship
    valid                                       // avaliable for ship
};


// status of a coordinate in the player map
enum class MapCoord {
    empty,                                      // 0, not yet guessed
    shipExist,                                  // 1, not yet guessed
    shipHit,                                    // 2, guessed
    shipSunk,                                   // 3, guessed
    shipMiss                                    // 4, guessed
};

// whether a coordinate has been guessed or not
enum class GuessCoord {
    outOfBounds,                                // outside the map
    guessed,                                    // already been guessed once
    notYetGuessed                               // not yet been guessed
};

struct playerData
{
   int score;                                  // player score
   char name[STR_LEN];                         // name of player
};

class Player {
    Ship ships[NO_OF_SHIPS];                    // array of Ship objects
    MapCoord shipMap[MAP_SIZE][MAP_SIZE];       // 2D map of all coordinates
    int score;                                  // player score
    char name[STR_LEN];                         // name of player
public:
    Player();
    
    // input functions
    void inputName();                           // inputs name of player
    void inputShips();                          // inputs details of Ship objects
    
    // map functions
    void printFullMap();                        // prints complete map
    void drawShip(Ship);                        // changes 0 to 1 in the map
    
    // ship functions
    bool inMap(Ship);                           // checks if a Ship object lies in player map
    bool mapFree(Ship);                         // checks if coordinates are free for a ship
    ShipCoord getStatus(Ship);                  // returns the validity of Ship object's coordinates
    bool isSunk(Ship);                          // checks if a given ship is sunk 
    void sink(Ship);                            // sink a ship (changes
                                                // CoordStatus::shipHit to CoordStatus::shipSunk)
    
    // guess coordinate functions
    GuessCoord guessValidity(Coord);            // checks if an entered coordinate guess is valid
    void getsHit(Coord);                        // updates map based on guessed coordinates
    MapCoord coordValue(Coord);                 // returns MapCoord value for a coordinate
    
    // getter functions
    char* getName();                            // returns player name
    
    // score functions 
    void increaseScore(int);                    // increases score by a value

};


#endif /* player_h */
