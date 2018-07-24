//
// Created by Kaib Cropley on 7/23/2018.
//

#ifndef BATTLESHIP_MENU_H
#define BATTLESHIP_MENU_H


#include "player.h"

class Menu {
public:
    // Constructor
    Menu();

    // Destructor
    ~Menu();

    // Asks player for the amount of players and creates the player objects
    void setGameUp();

private:
    // Board information
    int width;
    int height;

    // Players for the game
    Player *playerOne;
    Player *playerTwo;

    // Finishes game by resetting pointers
    void finishGame();

    // Plays through a turn for a single player game
    void singlePlayer();

    // Puts ships on the computers board for each live they have
    void placeRandomShips(Player *p);

    // Prints name, lives and board for given player
    void printPlayerInfo(Player *p);
};


#endif //BATTLESHIP_MENU_H
