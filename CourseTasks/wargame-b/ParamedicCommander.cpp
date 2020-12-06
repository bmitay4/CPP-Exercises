/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "ParamedicCommander.hpp"

#include <math.h>

ParamedicCommander::ParamedicCommander(int team) : Paramedic(team) {
    hitPoints = fullhitPoints = 200;
    soldierTitle = "ParamedicCommander";
    soldierTitleTable = "PmedC";
}
ParamedicCommander::~ParamedicCommander() {
    cout << "ParamedicCommander Destructor Called" << endl;
}
void ParamedicCommander::takeAction() {
    int count = 0;
    setField();
    cout << this->toString() << " Take Action" << endl;
    Soldier* tempSoldier;
    int currentHP, maxHP, tempSoldierTeam;

    for (int i = 0; i < myField.size(); i++) {
        tempSoldier = get<3>(myField[i]);
        currentHP = tempSoldier->getHP();
        maxHP = tempSoldier->getMAXHP();
        tempSoldierTeam = tempSoldier->getTeamID();

        if (tempSoldierTeam == soldierTeam && get<0>(myField[i]) <= sqrt(2)) {
            if (currentHP != maxHP) {
                tempSoldier->setHP();
                cout << tempSoldier->toString() << " healed! his HP fully restored" << endl;
                count++;
            }
        }
    }
    if (count == 0) cout << this->toString() << " Took No Action " << endl;
    ActivateAll();
}
void ParamedicCommander::ActivateAll() {
    cout << "ParamedicCommander command all Paramedics to care of the injured!" << endl;
    Soldier* tempSoldier;
    int tempSoldierTeam, tempSoldierAlive;
    string tempSoldierTitle;

    for (int i = 0; i < myField.size(); i++) {
        tempSoldier = get<3>(myField[i]);
        tempSoldierTeam = tempSoldier->getTeamID();
        tempSoldierAlive = tempSoldier->isAlive();
        tempSoldierTitle = tempSoldier->getTitle();
        if (tempSoldierTeam == soldierTeam && (tempSoldierTitle.compare("Paramedic") == 0) && tempSoldierAlive) {
            if (!tempSoldier->checkBoard())
                tempSoldier->setBoard(board);
            tempSoldier->takeAction();
        }
    }
}