#include <iostream>
#include <cassert>
#include "board.h"
#include "player.h"

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
}

void testAll() {
//    testBoard();
    testPlayer();
}

int main() {
    testAll();
    std::cout << "Done with testing!" << std::endl;
    return 0;
}