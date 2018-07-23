//
// Created by Kaib Cropley on 7/20/2018.
//

#include "player.h"

// Constructor
Player::Player(std::string name, int lives, int width, int height) :
        name{name}, lives{lives} {
    grid = new Board(width, height);
    std::vector<Ship> toCopy(lives);
    ships = toCopy;

    /////////////////////////////////////////////
    //////////// temp for testing ///////////////
    /////////////////////////////////////////////
    for (int i{0}; i < lives; i++) {
        ships[i] = Ship(i, i);
    }
}

// Destructor
Player::~Player() {

}

// Returns name of the player
std::string Player::GetName() {
    return name;
}

// Returns number of players lives
int &Player::GetLives() {
    return lives;
}

// Player gets "board attacked"
// Returns: -1 = out of bounds, 0 = miss, 1 = hit
int Player::Attacked(int col, int row) {
    if (col > grid->getWidth() || col < 0 ||
        row > grid->getHeight() || row < 0) {
        return -1;
    }

    for (int i{0}; i < ships.size(); i++) {
        if (col == ships[i].col && row == ships[i].row) {
            grid->Hit(col, row);
            return 1;
        }
    }

    grid->Miss(col, row);
    return 0;
}
