/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "Board.hpp"

#include <math.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

//Constructor
WarGame::Board::Board(uint numRows, uint numCols) : board(numRows, std::vector<Soldier*>(numCols, nullptr)) {}

//Destructor
WarGame::Board::~Board() {
    cout << "Board Destructor Called" << endl;
}
Soldier*& WarGame::Board::operator[](pair<int, int> location) {
    if (location.first >= board.size() || location.second >= board[0].size())
        throw std::invalid_argument("out of bounds");
    return board[location.first][location.second];
}
Soldier* WarGame::Board::operator[](pair<int, int> location) const {
    return board[location.first][location.second];
}
void WarGame::Board::makeStep(pair<int, int>& source, MoveDIR direction) {
    int x = source.first, y = source.second;
    Soldier* tempSoldier = board[x][y];
    if (direction == Up)
        source.first++;
    else if (direction == Down)
        source.first--;
    else if (direction == Left)
        source.second--;
    else if (direction == Right)
        source.second++;
    board[source.first][source.second] = tempSoldier;
    board[x][y] = nullptr;
}
bool WarGame::Board::checkStep(pair<int, int> source, MoveDIR direction) {
    if (direction == Up)
        source.first++;
    else if (direction == Down)
        source.first--;
    else if (direction == Left)
        source.second--;
    else if (direction == Right)
        source.second++;

    if (source.first >= 0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size()) {
        Soldier* tempSoldier = board[source.first][source.second];
        if (!tempSoldier)
            return true;
        else
            return false;
    } else
        return false;
}
bool WarGame::Board::verifySource(uint player_number, pair<int, int> source) {
    if (source.first >= 0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size()) {
        Soldier* tempSoldier = board[source.first][source.second];
        if (tempSoldier && tempSoldier->getTeamID() == player_number)
            return true;
        else
            return false;
    } else
        return false;
}
bool WarGame::Board::verifyTarget(pair<int, int> source, MoveDIR direction) {
    if (checkStep(source, direction))
        return true;
    else
        return false;
}
void WarGame::Board::boardAction(Soldier* soldier, pair<int, int> source, MoveDIR direction) {
    //printBoard();
    cout << (*soldier).toString() << " moved from " << (*soldier).getLocation().first << "," << (*soldier).getLocation().second << " ";
    makeStep(source, direction);
    (*soldier).setBoard(board);
    cout << "to " << (*soldier).getLocation().first << "," << (*soldier).getLocation().second << endl;
    // printBoard();
    (*soldier).takeAction();
    cout << endl;
}
void WarGame::Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
    if (!verifySource(player_number, source))
        throw std::invalid_argument("source error");
    else if (!verifyTarget(source, direction))
        throw std::invalid_argument("target error");
    else {
        Soldier* tempSoldier = board[source.first][source.second];
        (*tempSoldier).setBoard(board);
        boardAction(tempSoldier, source, direction);
    }
}
bool WarGame::Board::has_soldiers(uint player_number) const {
    //   cout << "has_soldiers() function called, team " << player_number << endl;

    Soldier* tempSoldier;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            tempSoldier = board[i][j];
            if (tempSoldier && (*tempSoldier).getTeamID() == player_number && tempSoldier->isAlive() != 0)
                return true;
        }
    }
    return false;
}
//Prints the board
void WarGame::Board::printBoard() {
    cout << "Current Board" << endl;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            if (board[i][j] && board[i][j]->isAlive() != 0)
                cout << (*board[i][j]).toStringTable() << "   ";
            else
                cout << "|NULL|"
                     << "\t";
        }
        cout << "\n"
             << endl;
    }
}
void WarGame::Board::printCell(pair<int, int> source) {
    cout << "(" << source.first << "," << source.second << ")" << endl;
}