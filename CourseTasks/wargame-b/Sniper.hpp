/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#ifndef _SNIPER_H
#define _SNIPER_H

#include "Soldier.hpp"

class Sniper : public Soldier {
   protected:
    int damagePoints;  //Soldier's damage ability

   public:
    Sniper(int);
    virtual ~Sniper();
    virtual void takeAction();
    virtual Soldier* getTarget();
};

#endif