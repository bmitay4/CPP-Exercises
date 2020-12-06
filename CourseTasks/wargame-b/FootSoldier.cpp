/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "FootSoldier.hpp"

#include <bits/stdc++.h>

FootSoldier::FootSoldier(int team) : Soldier(team) {
    hitPoints = fullhitPoints = 100;
    damagePoints = 10;
    soldierTitle = "FootSoldier";
    soldierTitleTable = "FS";
}
FootSoldier::~FootSoldier() {
    cout << "FootSoldier Destructor Called" << endl;
}
void FootSoldier::takeAction() {
    setField();
    Soldier* tempSoldier = getTarget();

    cout << this->toString() << " Take Action" << endl;
    if (tempSoldier) {
        tempSoldier->takeDamage(damagePoints);
        cout << "A Hit! " << tempSoldier->toString() << " lost " << damagePoints << " HP\n"
             << endl;
        if (!tempSoldier->isAlive()) {
            cout << tempSoldier->toString() << ", has been killed, removed from the board\n"
                 << endl;
            tempSoldier->setAlive(0);
        }
    } else
        cout << this->toString() << " Took No Action" << endl;
}
Soldier* FootSoldier::getTarget() {
    Soldier* tempSoldier;
    int tempSoldierTeam, tempSoldierAlive;
    for (int i = 0; i < myField.size(); i++) {
        tempSoldier = get<3>(myField[i]);
        tempSoldierTeam = tempSoldier->getTeamID();
        tempSoldierAlive = tempSoldier->isAlive();
        if (tempSoldierTeam != soldierTeam && tempSoldierAlive) return tempSoldier;
    }

    return nullptr;
}