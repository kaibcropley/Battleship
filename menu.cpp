//
// Created by Kaib Cropley on 7/23/2018.
//

#include <iostream>
#include "menu.h"

// Constructor
Menu::Menu() : playerOne{nullptr}, playerTwo{nullptr} {

}

// Destructor
Menu::~Menu() {

}

// Asks player for the amount of players and creates the player objects
void Menu::setGameUp() {
    int amountOfPlayers = 0;
    do {
        std::cout << "How many players? 1 or 2: ";
        std::cin >> amountOfPlayers;
    } while (amountOfPlayers != 1 && amountOfPlayers != 2);

    int amountOfLives;
    std::cout << "Lives: ";
    std::cin >> amountOfLives;
    std::cout << "Board width: ";
    std::cin >> width;
    std::cout << "Board height: ";
    std::cin >> height;

    std::string playerName;
    std::cout << "Player one name: ";
    std::cin >> playerName;
    playerOne = new Player(playerName, amountOfLives,
                           width, height);

    if (amountOfPlayers > 1) {
        std::cout << "Player two name: ";
        std::cin >> playerName;
        playerTwo = new Player(playerName, amountOfLives,
                               width, height);
    } else {
        playerTwo = new Player("Computer", amountOfLives,
                               width, height);
        singlePlayer();
    }
}

// Finishes game by resetting pointers
void Menu::finishGame() {
    delete playerOne;
    delete playerTwo;
}

// Plays through a turn for a single player game
void Menu::singlePlayer() {
    std::cout << "Goal is to destroy all the "
            "computers battleships" << std::endl;
    std::cout << "Example input \"0 3\" will shoot at "
            "column 0, row 3" << std::endl << std::endl;

    placeRandomShips(playerTwo);
    printPlayerInfo(playerTwo);

    while (playerTwo->GetLives() > 0) {
        std::cout << "Shoot at: ";
        int col, row;
        std::cin >> col >> row;
        playerTwo->Attacked(col, row);
        printPlayerInfo(playerTwo);
    }

    std::cout << "You win!!!" << std::endl;
    finishGame();
}

// Puts ships on the computers board for each live they have
void Menu::placeRandomShips(Player *p) {
    for (int i{0}; i < p->GetLives(); i++) {
        p->AddShip((rand() % width), (rand() % height));
    }
}

// Prints name, lives and board for given player
void Menu::printPlayerInfo(Player *p) {
    std::cout << "--------------------" << std::endl <<
              p->GetName() << std::endl << "Lives: " <<
              p->GetLives() << std::endl;
    playerTwo->printBoard();
}


