//
// Created by Kaib Cropley on 7/20/2018.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <string>
#include <vector>
#include "board.h"

class Player {
public:
    // Constructor
    Player(std::string name, int lives, int width, int height);

    // Destructor
    ~Player();

    // Returns name of the player
    std::string GetName();

    // Returns number of players lives
    int& GetLives();

    // Player gets "board attacked"
    // Returns: -1 = out of bounds, 0 = miss, 1 = hit
    int Attacked(int col, int row);

private:
    // Players name
    std::string name;

    // Players remaining lives
    int lives;

    // Players personal board
    Board* grid;

    // Ship object to hold it's board position
    struct Ship {
        Ship(int col, int row) : col{col}, row{row} {};
        int col;
        int row;
    };

    // Vector of all ships this player has
    std::vector<Ship> ships;

};


#endif //BATTLESHIP_PLAYER_H
