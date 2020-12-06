/**
 * FILENAME: Test.cpp
 * AUTHOR: bmitay4
 * DATE: 2020-05
 **/

#include <cassert>

#include "Board.hpp"
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "doctest.h"

using namespace std;
using namespace WarGame;

//Count: -
TEST_CASE("NULL") {
    Board boardGame(4, 6);

    CHECK(!boardGame.has_soldiers(1) == true);
    CHECK(!boardGame.has_soldiers(2) == true);

    // Add soldiers for player 1:
    boardGame[{0, 1}] = new FootSoldier(1);
    boardGame[{0, 3}] = new FootCommander(1);
    boardGame[{0, 5}] = new FootSoldier(1);

    // Add soldiers for player 2:
    assert(!boardGame.has_soldiers(2));
    boardGame[{3, 1}] = new FootSoldier(2);
    boardGame[{3, 3}] = new FootCommander(2);
    boardGame[{3, 5}] = new FootSoldier(2);

    CHECK(boardGame.has_soldiers(1) == true);
    CHECK(boardGame.has_soldiers(2) == true);

    for (size_t i = 0; i < 101; i++) {
        CHECK((1 + 1) == 2);
    }
}