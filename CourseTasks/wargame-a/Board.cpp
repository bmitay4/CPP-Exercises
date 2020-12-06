#include "Board.hpp"

#include <iostream>
using namespace std;

Soldier*& WarGame::Board::operator[](std::pair<int, int> location) {
    return board[location.first][location.second];
}
Soldier* WarGame::Board::operator[](std::pair<int, int> location) const {
    return board[location.first][location.second];
}
void WarGame::Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
}
bool WarGame::Board::has_soldiers(uint player_number) const {
    Soldier* temp;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            temp = board[i][j];
            if (temp && (*temp).getTeamID() == player_number) return true;
        }
    }
    return false;
}