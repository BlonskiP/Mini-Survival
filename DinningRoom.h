//
// Created by wilk on 08.06.19.
//

#ifndef SURVIVAL_DINNINGROOM_H
#define SURVIVAL_DINNINGROOM_H


#include "Room.h"

class Dinningroom : public Room {
public:
    void RoomEfect(Creature *creature);
    Dinningroom();
};


#endif //SURVIVAL_DINNINGROOM_H
