//
//  coord.h
//  Battleship
//

#ifndef coord_h
#define coord_h

#include <iostream>

struct Coord {
    int x, y;
    void input() {
        std::cout << "X: ";
        std::cin >> x;
        std::cout << "Y: ";
        std::cin >> y;
    }
};


#endif /* coord_h */
