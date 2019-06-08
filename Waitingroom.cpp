//
// Created by wilk on 08.06.19.
//

#include "Waitingroom.h"

void Waitingroom::RoomEfect(Creature *creature) {
    creature->progress=0;
    creature->setRoom(this);
}

Waitingroom::Waitingroom() {
    this->roomName="Waitingroom";

}

bool Waitingroom::Use(Creature *creature) {
    RoomEfect(creature);

    return true;
}
