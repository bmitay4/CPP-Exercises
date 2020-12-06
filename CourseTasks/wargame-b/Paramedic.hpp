/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#ifndef _PARAMEDIC_H
#define _PARAMEDIC_H

#include "Soldier.hpp"

class Paramedic : public Soldier {
   public:
    Paramedic(int);
    virtual ~Paramedic();
    virtual void takeAction();
    virtual Soldier* getTarget() {
        return nullptr;
    }
};

#endif