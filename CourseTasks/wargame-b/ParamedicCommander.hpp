/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
**/
#ifndef _PARAMEDICCOMMANDER_H
#define _PARAMEDICCOMMANDER_H

#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic {
   public:
    ParamedicCommander(int);
    virtual ~ParamedicCommander();
    virtual void takeAction();
    virtual Soldier* getTarget() {
        return nullptr;
    }
    void ActivateAll();
};

#endif