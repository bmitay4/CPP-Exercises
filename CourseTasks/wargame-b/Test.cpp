/**
 * FILENAME: Test.cpp, 64 tests
 * AUTHOR: bmitay4
 * DATE: 2020-06
 **/

#include <cassert>

#include "Board.hpp"
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "doctest.h"

using namespace std;
using namespace WarGame;

//Count: 6
TEST_CASE("6x6 board, 4vs1, team 2 should lose after moves") {
    Board boardGame(6, 6);

    CHECK(!boardGame.has_soldiers(1) == true);
    CHECK(!boardGame.has_soldiers(2) == true);

    //Add soldiers for player 1:
    boardGame[{0, 0}] = new FootSoldier(1);
    boardGame[{0, 1}] = new FootCommander(1);
    boardGame[{0, 2}] = new Sniper(1);
    boardGame[{0, 3}] = new Sniper(1);

    //Add soldiers for player 2:
    boardGame[{4, 0}] = new FootSoldier(2);

    CHECK(boardGame.has_soldiers(1) == true);
    CHECK(boardGame.has_soldiers(2) == true);

    boardGame.move(2, {4, 0}, Board::MoveDIR::Down);
    boardGame.move(1, {0, 0}, Board::MoveDIR::Up);
    boardGame.move(1, {0, 1}, Board::MoveDIR::Up);
    boardGame.move(1, {0, 2}, Board::MoveDIR::Up);
    boardGame.move(1, {0, 3}, Board::MoveDIR::Up);

    CHECK(!boardGame.has_soldiers(1) == false);
    CHECK(!boardGame.has_soldiers(2) == true);  //Game over, team 2 has no players on the field
}
//Count: 17
TEST_CASE("5X5 board, 2 footsoldiers and a sniper vs footsoldier and paramedic, team 2 lose") {
    Board boardGame(5, 5);

    //Add soldiers for player 1:
    boardGame[{0, 0}] = new FootSoldier(1);
    boardGame[{0, 2}] = new FootSoldier(1);
    boardGame[{0, 4}] = new Sniper(1);

    //Add soldiers for player 2:
    boardGame[{4, 3}] = new FootSoldier(2);
    boardGame[{4, 1}] = new Paramedic(2);

    CHECK(boardGame.has_soldiers(1) == true);
    CHECK(boardGame.has_soldiers(2) == true);

    CHECK_NOTHROW(boardGame.move(1, {0, 0}, Board::MoveDIR::Right));
    CHECK_NOTHROW(boardGame.move(2, {4, 1}, Board::MoveDIR::Down));
    CHECK_NOTHROW(boardGame.move(1, {0, 2}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(2, {4, 3}, Board::MoveDIR::Down));
    CHECK_NOTHROW(boardGame.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(2, {3, 1}, Board::MoveDIR::Right));  //Heal FootSoldier(2)
    CHECK_NOTHROW(boardGame.move(1, {0, 4}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(2, {3, 3}, Board::MoveDIR::Down));
    CHECK_NOTHROW(boardGame.move(1, {1, 4}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(2, {2, 3}, Board::MoveDIR::Left));
    CHECK_NOTHROW(boardGame.move(1, {2, 4}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(2, {2, 2}, Board::MoveDIR::Left));
    CHECK_NOTHROW(boardGame.move(1, {3, 4}, Board::MoveDIR::Up));

    CHECK(!boardGame.has_soldiers(1) == false);
    CHECK(!boardGame.has_soldiers(2) == true);  //Game over, team 2 has no players on the field
}
//Count: 10
TEST_CASE("6X3 board, snipers squad vs 2 paramedics..a bloodbath..") {
    Board boardGame(6, 3);

    CHECK(!boardGame.has_soldiers(1) == true);
    CHECK(!boardGame.has_soldiers(2) == true);

    //Add soldiers for player 1:
    boardGame[{0, 0}] = new Sniper(1);
    boardGame[{0, 1}] = new SniperCommander(1);
    boardGame[{0, 2}] = new Sniper(1);

    //Add soldiers for player 2:
    boardGame[{5, 0}] = new Paramedic(2);
    boardGame[{5, 2}] = new Paramedic(2);

    CHECK(boardGame.has_soldiers(1) == true);
    CHECK(boardGame.has_soldiers(2) == true);

    CHECK_THROWS(boardGame.move(1, {0, 0}, Board::MoveDIR::Right));
    CHECK_THROWS(boardGame.move(1, {0, 2}, Board::MoveDIR::Left));
    CHECK_THROWS(boardGame.move(2, {5, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(2, {5, 2}, Board::MoveDIR::Right));

    //Game will end in one move by SniperCommander
    CHECK_NOTHROW(boardGame.move(1, {0, 1}, Board::MoveDIR::Up));

    CHECK(!boardGame.has_soldiers(2) == true);  //Game over, team 2 has no players on the field
}
//Count: 11
TEST_CASE("4X4 board, look for out of bounds errors") {
    Board boardGame(4, 4);

    //Add soldiers for player 1:
    boardGame[{0, 0}] = new FootSoldier(1);
    boardGame[{0, 1}] = new FootCommander(1);
    boardGame[{0, 2}] = new Sniper(1);
    boardGame[{0, 3}] = new Sniper(1);

    //Add soldiers for player 2:
    boardGame[{3, 0}] = new FootSoldier(2);

    CHECK_THROWS(boardGame.move(2, {3, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(2, {0, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(2, {3, 0}, Board::MoveDIR::Left));
    CHECK_THROWS(boardGame.move(1, {0, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(boardGame.move(1, {0, 0}, Board::MoveDIR::Left));
    CHECK_THROWS(boardGame.move(1, {5, 5}, Board::MoveDIR::Left));

    CHECK_NOTHROW(boardGame.move(1, {0, 0}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(1, {0, 2}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(1, {0, 3}, Board::MoveDIR::Up));
    CHECK_NOTHROW(boardGame.move(1, {1, 0}, Board::MoveDIR::Up));
}
//Count: 20
TEST_CASE("2X7 board, look for source&target error") {
    Board boardGame(2, 7);

    //Add soldiers for player 1:
    boardGame[{0, 0}] = new FootSoldier(1);
    boardGame[{0, 1}] = new FootCommander(1);
    boardGame[{0, 2}] = new FootSoldier(1);
    boardGame[{0, 3}] = new Sniper(1);
    boardGame[{0, 4}] = new SniperCommander(1);
    boardGame[{0, 5}] = new Paramedic(1);
    boardGame[{0, 6}] = new ParamedicCommander(1);

    //Add soldiers for player 2:
    boardGame[{1, 0}] = new FootSoldier(2);
    boardGame[{1, 1}] = new FootCommander(2);
    boardGame[{1, 2}] = new FootSoldier(2);
    boardGame[{1, 3}] = new Sniper(1);
    boardGame[{1, 4}] = new SniperCommander(2);
    boardGame[{1, 5}] = new Paramedic(2);
    boardGame[{1, 6}] = new ParamedicCommander(2);

    //All borad is full, soldiers can't move at all
    CHECK_THROWS(boardGame.move(1, {0, 0}, Board::MoveDIR::Right));
    CHECK_THROWS(boardGame.move(1, {0, 3}, Board::MoveDIR::Left));
    CHECK_THROWS(boardGame.move(1, {0, 6}, Board::MoveDIR::Left));
    CHECK_THROWS(boardGame.move(2, {1, 1}, Board::MoveDIR::Right));
    CHECK_THROWS(boardGame.move(2, {1, 2}, Board::MoveDIR::Right));
    CHECK_THROWS(boardGame.move(2, {1, 4}, Board::MoveDIR::Left));

    CHECK_THROWS(boardGame.move(1, {0, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(1, {0, 2}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(1, {0, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(1, {0, 4}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(1, {0, 5}, Board::MoveDIR::Up));
    CHECK_THROWS(boardGame.move(1, {0, 6}, Board::MoveDIR::Up));

    CHECK_THROWS(boardGame.move(2, {1, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(boardGame.move(2, {1, 1}, Board::MoveDIR::Down));
    CHECK_THROWS(boardGame.move(2, {1, 2}, Board::MoveDIR::Down));
    CHECK_THROWS(boardGame.move(2, {1, 3}, Board::MoveDIR::Down));
    CHECK_THROWS(boardGame.move(2, {1, 4}, Board::MoveDIR::Down));
    CHECK_THROWS(boardGame.move(2, {1, 5}, Board::MoveDIR::Down));
    CHECK_THROWS(boardGame.move(2, {1, 6}, Board::MoveDIR::Down));
}