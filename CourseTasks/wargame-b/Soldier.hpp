/**
 * DATE:    2020-06
 * AUTHOR: bmitay4
 * DESCRIPTION: Soldier program, from which there are
 *              inheritance to other classes containing other types of soldiers.
**/
#pragma once
#ifndef _SOLDIER_H
#define _SOLDIER_H

#include <iostream>
#include <iterator>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

class Soldier {
   protected:
    int soldierTeam;    //Soldier's team
    int hitPoints;      //Soldier's current life point
    int fullhitPoints;  //Soldier's total life point
    int alive;
    string soldierTitle;       //Soldier's role
    string soldierTitleTable;  //Soldier's role

    std::vector<std::vector<Soldier*>> board;
    pair<int, int> selfLocation;  //Self location of the soldier
    //tuple that contains 5 elements of the soldier:
    //distance from other soldier, current position (pair), team number, pointer to the soldier, alive or dead signal
    vector<tuple<float, pair<int, int>, int, Soldier*, int>> myField;  //Current field, from the soldier's perspective

   public:
    Soldier(int);
    virtual ~Soldier();
    void takeDamage(int);
    virtual void takeAction() = 0;
    virtual Soldier* getTarget() = 0;

    bool isAlive();
    void setAlive(int);
    void setField();
    void setHP();
    int getHP();
    int getMAXHP();
    void setBoard(std::vector<std::vector<Soldier*>>&);
    bool checkBoard();
    pair<int, int> getLocation();
    void setLocation(int);
    void setLocation(int, int);
    float calcDistance(pair<int, int>, pair<int, int>);
    int getTeamID();
    string getTitle();
    string toString();
    string toStringTable();
};

#endif