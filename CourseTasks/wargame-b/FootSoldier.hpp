/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#ifndef _FOOTSOLDIER_H
#define _FOOTSOLDIER_H

#include "Soldier.hpp"

class FootSoldier : public Soldier {
   protected:
    int damagePoints;  //Soldier's damage ability

   public:
    FootSoldier(int);
    virtual ~FootSoldier();
    virtual void takeAction();
    virtual Soldier* getTarget();
};

#endif