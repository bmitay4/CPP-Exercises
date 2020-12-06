/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "FootCommander.hpp"

#include <string>

#include "Board.hpp"

FootCommander::FootCommander(int team) : FootSoldier(team) {
    hitPoints = fullhitPoints = 150;
    damagePoints = 20;
    soldierTitle = "FootCommander";
    soldierTitleTable = "FC";
}
FootCommander::~FootCommander() {
    cout << "FootCommander Destructor Called" << endl;
}
void FootCommander::takeAction() {
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
        cout << endl;
        ActivateAll();
    } else
        cout << this->toString() << " Took No Action" << endl;
}
Soldier* FootCommander::getTarget() {
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
void FootCommander::ActivateAll() {
    cout << "FootCommander command all FootSoldiers to shoot!" << endl;
    Soldier* tempSoldier;
    int tempSoldierTeam, tempSoldierAlive;
    string tempSoldierTitle;

    for (int i = 0; i < myField.size(); i++) {
        tempSoldier = get<3>(myField[i]);
        tempSoldierTeam = tempSoldier->getTeamID();
        tempSoldierAlive = tempSoldier->isAlive();
        tempSoldierTitle = tempSoldier->getTitle();
        if (tempSoldierTeam == soldierTeam && (tempSoldierTitle.compare("FootSoldier") == 0) && tempSoldierAlive) {
            if (!tempSoldier->checkBoard())
                tempSoldier->setBoard(board);
            tempSoldier->takeAction();
        }
    }
}