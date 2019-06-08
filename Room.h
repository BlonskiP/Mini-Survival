//
// Created by wilk on 08.06.19.
//

#ifndef SURVIVAL_ROOM_H
#define SURVIVAL_ROOM_H
#include <mutex>
#include <vector>
#include "Creature.h"
#include <condition_variable>

using namespace std;
class Creature;
class Room {
private:
public:
    Room();
    string roomName="MissingName";
    mutex RoomAcces;
    condition_variable accesed;
    unique_lock<mutex> *lck;
    virtual bool Use(Creature *creature);
    virtual void RoomEfect(Creature *creature) = 0;
    void print();
};


#endif //SURVIVAL_ROOM_H
