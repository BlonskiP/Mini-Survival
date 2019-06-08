//
// Created by wilk on 08.06.19.
//

#include <unistd.h>
#include "Bedroom.h"

void Bedroom::RoomEfect(Creature *creature) {
    if(creature->getEnergy()>75)return;
    int prog=0;
    creature->setProgress(prog);
    if(creature->getEnergy()<75)
        while((creature->getEnergy()<creature->maxEnergy || creature->getProgress()<10) && creature->isAlive )
        {
            // accesed.wait_for(*lck,std::chrono::seconds(1));
            prog++;
            sleep(1);
            creature->setProgress(prog);
            creature->changeEnergyBy(5);
        }
}

Bedroom::Bedroom() {
    this->roomName="Bedroom";
}
