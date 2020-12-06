#ifndef _FOOTCOMMANDER_H
#define _FOOTCOMMANDER_H

#include "FootSoldier.hpp"

class FootCommander : public FootSoldier {
   private:
   public:
    FootCommander(int team) : FootSoldier(team) {  //Constructor
        hitPoints = 150;
        damagePoints = 20;
    }
};

#endif