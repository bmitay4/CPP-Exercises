#ifndef _FOOTSOLDIER_H
#define _FOOTSOLDIER_H

#include "Soldier.hpp"

class FootSoldier : public Soldier {
   protected:
    int damagePoints;

   public:
    FootSoldier(int team) : Soldier(team) {  //Constructor
        hitPoints = 100;
        damagePoints = 10;
    }
};

#endif