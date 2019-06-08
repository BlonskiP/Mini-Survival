//
// Created by wilk on 07.06.19.
//

#ifndef SURVIVAL_CREATURE_H
#define SURVIVAL_CREATURE_H


#include <thread>
#include "Room.h"
#include <condition_variable>
using namespace std;
class Room;
class Creature {
private:


    int hunger;
    int energy;
    int x;
    int y;

    Room *room;
public:
    const int maxHunger=100;
    const int maxEnergy=100;
    condition_variable cvCreatureWorking;
    int progress =0;
    string name;
    mutex statsAcces;
    Creature(string name);
    thread creatureThread;
    int getHunger();
    int getEnergy();
    int getProgress();
    void changeHungerBy(int change);
    void changeEnergyBy(int change);
    void setProgress(int prog);
    bool CheckIfIsAlive();
    bool isAlive;
    void setRoom(Room *room);
    void Survive();
    void print();
    Room * getRoom();


};


#endif //SURVIVAL_CREATURE_H
