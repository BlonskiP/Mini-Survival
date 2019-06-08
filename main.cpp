#include <iostream>
#include "Creature.h"
#include "Room.h"
#include "ConsoleManager.h"

int main() {
    ConsoleManager CM;
    CM.BeginSurvival();
    CM.reprint();
    while(true)CM.reprint();
    endwin();
    return 0;
}