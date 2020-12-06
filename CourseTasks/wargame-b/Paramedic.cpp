/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#include "Paramedic.hpp"

#include <math.h>

Paramedic::Paramedic(int team) : Soldier(team) {
    hitPoints = fullhitPoints = 100;
    soldierTitle = "Paramedic";
    soldierTitleTable = "Pmed";
}
Paramedic::~Paramedic() {
    cout << "Paramedic Destructor Called" << endl;
}
void Paramedic::takeAction() {
    int count = 0;
    setField();
    cout << this->toString() << " Take Action" << endl;
    Soldier *tempSoldier;
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
}