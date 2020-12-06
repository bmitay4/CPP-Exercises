/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "Soldier.hpp"

#include <bits/stdc++.h>
#include <math.h>

Soldier::Soldier(int team) : soldierTeam(team) {
    alive = 1;
    selfLocation = make_pair(0, 0);
}
Soldier::~Soldier() {
    cout << "Soldier Destructor Called" << endl;
}
int Soldier::getTeamID() {
    return soldierTeam;
}
void Soldier::setHP() {
    hitPoints = fullhitPoints;
}
int Soldier::getHP() {
    return hitPoints;
}
int Soldier::getMAXHP() {
    return fullhitPoints;
}
void Soldier::setAlive(int value) {
    alive = value;
}
void Soldier::takeDamage(int dmg) {
    hitPoints = hitPoints - dmg;
    if (hitPoints < 1) alive = 0;
}
void Soldier::setBoard(std::vector<std::vector<Soldier*>>& b) {
    board = b;
    Soldier* tempSoldier;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            tempSoldier = board[i][j];
            if (tempSoldier)
                (*tempSoldier).setLocation(i, j);
        }
    }
}
bool Soldier::isAlive() {
    if (hitPoints > 0)
        return true;
    else {
        alive = 0;
        return false;
    }
}
bool Soldier::checkBoard() {
    if (!board.empty())
        return true;
    else
        return false;
}
void Soldier::setLocation(int i, int j) {
    selfLocation.first = i;
    selfLocation.second = j;
}
void Soldier::setLocation(int direction) {
    if (direction == 0)
        selfLocation.first++;
    else if (direction == 1)
        selfLocation.first--;
    else if (direction == 2)
        selfLocation.second--;
    else if (direction == 3)
        selfLocation.second++;
}
pair<int, int> Soldier::getLocation() {
    return selfLocation;
}
void Soldier::setField() {
    if (!myField.empty()) myField.clear();

    Soldier* tempSoldier;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            tempSoldier = board[i][j];
            if (tempSoldier && tempSoldier != this) {
                tuple<float, pair<int, int>, int, Soldier*, int> t(calcDistance((*tempSoldier).getLocation(), getLocation()), (*tempSoldier).getLocation(), (*tempSoldier).getTeamID(), tempSoldier, alive);
                myField.push_back(t);
            }
        }
    }
    sort(myField.begin(), myField.end());
}
float Soldier::calcDistance(pair<int, int> soldierA, pair<int, int> soldierB) {
    int x1 = soldierA.first, y1 = soldierA.second, x2 = soldierB.first, y2 = soldierB.second;
    return (float)sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
//Return soldier's title
string Soldier::getTitle() {
    return soldierTitle;
}
//toString function, print soldier details
string Soldier::toString() {
    return soldierTitle + "[Team: " + to_string(soldierTeam) + ", HP:" + to_string(hitPoints) + ", At:(" + to_string(selfLocation.first) + "," + to_string(selfLocation.second) + ")]";
}
//toString function, print soldier details for table
string Soldier::toStringTable() {
    return soldierTitleTable + "[T: " + to_string(soldierTeam) + ", HP:" + to_string(hitPoints) + ", At:(" + to_string(selfLocation.first) + "," + to_string(selfLocation.second) + ")]";
}
