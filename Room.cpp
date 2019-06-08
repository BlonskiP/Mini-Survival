//
// Created by wilk on 08.06.19.
//

#include "Room.h"
#include "ConsoleManager.h"

using namespace std;



Room::Room() {}

void Room::print() {

}

bool Room::Use(Creature *creature) {
    unique_lock<std::mutex> lck(RoomAcces,defer_lock);
    bool succes = lck.try_lock();
    if(succes) {
        this->lck=&lck;

        creature->setRoom(this);
        RoomEfect(creature);

    }
    return succes;
}
