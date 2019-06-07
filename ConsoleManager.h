//
// Created by wilk on 08.06.19.
//

#ifndef SURVIVAL_CONSOLEMANAGER_H
#define SURVIVAL_CONSOLEMANAGER_H
#include <vector>
#include "Creature.h"
#include "Room.h"

using namespace std;
class Creature;

class ConsoleManager {
private:
    vector<Creature*> creatureList;
    vector<Room*> roomList;
public:
    void addNewCreature(Creature *creature);
    void printCreatureStats();
    void printAllRooms();
    void printAllCreatures();

};


#endif //SURVIVAL_CONSOLEMANAGER_H
