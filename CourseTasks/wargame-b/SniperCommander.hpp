/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#ifndef _SNIPERCOMMANDER_H
#define _SNIPERCOMMANDER_H

#include "Sniper.hpp"

class SniperCommander : public Sniper {
   public:
    SniperCommander(int);
    virtual ~SniperCommander();
    virtual void takeAction();
    virtual Soldier* getTarget();
    void ActivateAll();
};

#endif