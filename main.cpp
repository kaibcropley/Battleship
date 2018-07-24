#include <iostream>
#include <cassert>
#include "board.h"
#include "player.h"
#include "menu.h"

void testBoard() {
    Board board(5, 5);

    board.Print();

    board.Miss(4, 3);
    board.Hit(1, 2);
    board.Miss(2, 2);
    board.Hit(1, 3);
    board.Print();
}

void testPlayer() {
    Player p("Player 1", 5, 5, 5);

    assert(p.GetName() == "Player 1");
    assert(p.GetLives() == 5);
    p.GetLives()--;
    assert(p.GetLives() == 4);
    assert(p.GetLives() != 5);

    for (int i{0}; i < p.GetLives(); i++) {
        p.AddShip(i, i);
    }

    assert(p.Attacked(0, 0) == 1);
    assert(p.Attacked(1, 1) == 1);

    assert(p.Attacked(-1, 0) == -1);
    assert(p.Attacked(0, -1) == -1);
    assert(p.Attacked(10, 0) == -1);
    assert(p.Attacked(0, 10) == -1);

    assert(p.Attacked(0, 2) == 0);
    assert(p.Attacked(2, 0) == 0);

    p.printBoard();
}

void testMenu() {
    Menu m;
    m.setGameUp();
}

void testAll() {
    // If a test is commented out it prints to the console, uncomment for full
    // testing
//    testBoard();
//    testPlayer();
    testMenu();

}

int main() {
    testAll();
    std::cout << "Done with testing!" << std::endl;
    return 0;
}