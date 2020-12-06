/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#ifndef _FOOTCOMMANDER_H
#define _FOOTCOMMANDER_H

#include "FootSoldier.hpp"
class FootCommander : public FootSoldier {
   public:
    FootCommander(int);
    virtual ~FootCommander();
    virtual void takeAction();
    virtual Soldier* getTarget();
    void ActivateAll();
};

#endif