/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "Sniper.hpp"

Sniper::Sniper(int team) : Soldier(team) {
    hitPoints = fullhitPoints = 100;
    damagePoints = 50;
    soldierTitle = "Sniper";
    soldierTitleTable = "S";
}
Sniper::~Sniper() {
    cout << "Sniper Destructor Called" << endl;
}
void Sniper::takeAction() {
    setField();
    Soldier* tempSoldier = getTarget();

    cout << this->toString() << " Take Action" << endl;
    if (tempSoldier) {
        tempSoldier->takeDamage(damagePoints);
        cout << "A Hit! " << (*tempSoldier).toString() << " lost " << damagePoints << " HP" << endl;
        if (!(*tempSoldier).isAlive()) {
            cout << (*tempSoldier).toString() << ", has been killed, removed from the board" << endl;
            tempSoldier->setAlive(0);
        }
    } else
        cout << this->toString() << " Took No Action" << endl;
}
Soldier* Sniper::getTarget() {
    Soldier *tempSoldier, *topSoldier = nullptr;
    int tempSoldierTeam, tempSoldierAlive, currentHP, maxHP = 0;

    for (int i = 0; i < myField.size(); i++) {
        tempSoldier = get<3>(myField[i]);
        tempSoldierTeam = tempSoldier->getTeamID();
        tempSoldierAlive = tempSoldier->isAlive();
        currentHP = tempSoldier->getHP();
        if (tempSoldierTeam != soldierTeam && tempSoldierAlive && currentHP >= maxHP) {
            maxHP = currentHP;
            topSoldier = tempSoldier;
        }
    }
    if (topSoldier != nullptr) {
        return topSoldier;
    } else
        return nullptr;
}