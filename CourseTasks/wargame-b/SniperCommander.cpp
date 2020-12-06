/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "SniperCommander.hpp"

SniperCommander::SniperCommander(int team) : Sniper(team) {
    hitPoints = fullhitPoints = 120;
    damagePoints = 100;
    soldierTitle = "SniperCommander";
    soldierTitleTable = "SC";
}
SniperCommander::~SniperCommander() {
    cout << "SniperCommander Destructor Called" << endl;
}
void SniperCommander::takeAction() {
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
        cout << endl;
        ActivateAll();
    } else
        cout << this->toString() << " Took No Action" << endl;
}
Soldier* SniperCommander::getTarget() {
    Soldier *tempSoldier, *topSoldier;
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
    return topSoldier;
}
void SniperCommander::ActivateAll() {
    cout << "SniperCommander command all snipers to shoot!" << endl;
    Soldier* tempSoldier;
    int tempSoldierTeam, tempSoldierAlive;
    string tempSoldierTitle;

    for (int i = 0; i < myField.size(); i++) {
        tempSoldier = get<3>(myField[i]);
        tempSoldierTeam = tempSoldier->getTeamID();
        tempSoldierAlive = tempSoldier->isAlive();
        tempSoldierTitle = tempSoldier->getTitle();

        if (tempSoldierTeam == soldierTeam && (tempSoldierTitle.compare("Sniper") == 0) && tempSoldierAlive) {
            if (!tempSoldier->checkBoard())
                tempSoldier->setBoard(board);
            tempSoldier->takeAction();
        }
    }
}