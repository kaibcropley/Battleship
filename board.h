//
// Created by Kaib Cropley on 7/19/2018.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <string>


class Board {
public:
    // Constructor
    Board(int width, int height);

    // Destructor
    ~Board();

    // Prints board to console
    void Print();

    // Replaces spot on grid with an 'X'
    void Hit(int width, int height);

    // Replaces spot on grid with an 'O'
    void Miss(int width, int height);

    // Returns width of board
    int& getWidth();

    // Returns height of board
    int& getHeight();

private:
    // Coordinates system info
    int width;
    int height;

    // Max grid info
    const static int MAX_WIDTH = 30;
    const static int MAX_HEIGHT = 30;

    // Grid to hold printable grid
    std::string grid[MAX_WIDTH][MAX_HEIGHT];

};


#endif //BATTLESHIP_BOARD_H
