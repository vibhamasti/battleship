//
//  coord.h
//  Battleship
//

#ifndef coord_h
#define coord_h

#include <iostream>

struct Coord {
    int x, y;
    Coord();                    // default constructor
    Coord(int, int);            // parameterised constructor
    void input();               // inputs coordinate values
};

void Coord::input() {
    std::cout << "X: ";
    std::cin >> x;
    std::cout << "Y: ";
    std::cin >> y;
}

Coord::Coord() {
    x = 0;
    y = 0;
}

Coord::Coord(int a, int b) {
    x = a;
    y = b;
}

#endif /* coord_h */
