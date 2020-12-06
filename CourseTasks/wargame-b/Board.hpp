/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#ifndef _BOARD_H
#define _BOARD_H

#include <stdexcept>
#include <string>
#include <vector>

#include "Soldier.hpp"

namespace WarGame {

class Board {
   private:
    std::vector<std::vector<Soldier*>> board;
    bool isMapped = false;

   public:
    enum MoveDIR { Up,
                   Down,
                   Right,
                   Left };

    Board(uint, uint);
    ~Board();

    //operator for putting soldiers on the game-board during initialization.
    Soldier*& operator[](std::pair<int, int>);

    //operator for reading which soldiers are on the game-board.
    Soldier* operator[](std::pair<int, int>) const;

    //The function "move" tries to move the soldier of player "player" from the "source" location to the "target" location, and activates the special ability of the soldier.
    void move(uint, std::pair<int, int>, MoveDIR);

    //returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint) const;

    //Verify that the current position is owned by a player_number's team soldier
    bool verifySource(uint, std::pair<int, int>);

    //Verify that the next position is free move into
    bool verifyTarget(std::pair<int, int>, MoveDIR);

    void makeStep(std::pair<int, int>&, MoveDIR);
    bool checkStep(std::pair<int, int>, MoveDIR);

    void boardAction(Soldier*, pair<int, int>, MoveDIR);
    void printBoard();
    void printCell(pair<int, int>);
};

}  // namespace WarGame

#endif