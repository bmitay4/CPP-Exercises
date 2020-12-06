#pragma once
#ifndef _SOLDIER_H
#define _SOLDIER_H

class Soldier {
   protected:
    int playerTeam, hitPoints;

   public:
    Soldier(int team) : playerTeam(team) {}  //Constructor
    void reduceHP() {                        //Reduce soldier life by one
        hitPoints--;
    }
    int getTeamID() {
        return playerTeam;
    }
};

#endif