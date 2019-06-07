//
// Created by wilk on 07.06.19.
//

#ifndef SURVIVAL_CREATURE_H
#define SURVIVAL_CREATURE_H


#include <thread>
#include "Room.h"

using namespace std;
class Room;
class Creature {
private:
    const int maxHunger=100;
    const int maxEnergy=100;
    string name;
    int hunger;
    int energy;
    int x;
    int y;
    bool isAlive;
    Room *room;
public:
    Creature(string name);
    thread creatureThread;
    int getHunger();
    int getEnergy();
    void changeHungerBy(int change);
    void changeEnergyBy(int change);
    bool CheckIfIsAlive();
    void Survive();
    void print();


};


#endif //SURVIVAL_CREATURE_H
