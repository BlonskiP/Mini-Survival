//
// Created by wilk on 08.06.19.
//

#include "Room.h"
using namespace std;
void Room::addNewCreature(Creature *creature) {
    creatureList.push_back(creature);
}

Room::Room() {}

void Room::print() {

}

bool Room::Use(Creature *creature) {
    unique_lock<std::mutex> lck(RoomAcces,std::defer_lock);
    bool succes = lck.try_lock();
    if(succes) RoomEfect(creature);

    return succes;
}
