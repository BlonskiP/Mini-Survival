#include <iostream>
#include "Creature.h"
#include "Room.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Creature *c=new Creature("Andrzej");

    c->creatureThread.join();
    return 0;
}