//
// Created by wilk on 08.06.19.
//

#include <unistd.h>
#include "Kitchen.h"

Kitchen::Kitchen() {
    this->roomName="Kitchen";
}

void Kitchen::RoomEfect(Creature *creature) {
    if(creature->getHunger()>75)return;
    int prog=0;
    creature->setProgress(prog);
    if(creature->getHunger()<75)
    while((creature->getHunger()<creature->maxHunger || creature->getProgress()<10) && creature->isAlive )
    {
        // accesed.wait_for(*lck,std::chrono::seconds(1));
        prog++;
        sleep(1);
        creature->setProgress(prog);
        creature->changeHungerBy(5);
    }
}
