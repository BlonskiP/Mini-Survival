//
// Created by wilk on 08.06.19.
//

#include <cstring>
#include <unistd.h>
#include "ConsoleManager.h"
#include "Kitchen.h"
#include "Bedroom.h"
#include "DinningRoom.h"
#include "Waitingroom.h"
using namespace std;
vector<Creature*> ConsoleManager::creatureList;
vector<Room*> ConsoleManager::roomList;
bool ConsoleManager::survivalIsActive;
void ConsoleManager::addNewCreature(Creature *creature) {

}

ConsoleManager::ConsoleManager() {
    //CreateRooms
    ConsoleManager::roomList.push_back(new Kitchen());
    ConsoleManager::roomList.push_back(new Waitingroom());
    ConsoleManager::roomList.push_back(new Bedroom());
 //   ConsoleManager::roomList.push_back(new Dinningroom());
    //CreateCreatures//
    ConsoleManager::creatureList.push_back(new Creature("Maciek"));
    ConsoleManager::creatureList.push_back(new Creature("Mateusz"));
    ConsoleManager::creatureList.push_back(new Creature("Stefan"));
    ConsoleManager::creatureList.push_back(new Creature("Janek"));
    ConsoleManager::creatureList.push_back(new Creature("Staszek"));
    ///////////////////
    initscr();
    noecho();
    curs_set(0);
}

void ConsoleManager::BeginSurvival() {
    ConsoleManager::survivalIsActive=true;
    timeThread=thread(&ConsoleManager::TimeIsPassing,this);

}

void ConsoleManager::printCreatureStats() {
    int y=10; //starting y;
    int creatureCount=(int)ConsoleManager::creatureList.size();
    for(int i=0; i<creatureCount;i++) {
        move(y+i,0);
        Creature *& creature = ConsoleManager::creatureList[i];
        string name= creature->name;
        addstr(name.c_str());
        move(y+i,10);
        Room * room = creature->getRoom();
        string roomName=room->roomName;
        addstr(roomName.c_str());
        for(int j=0;j<creature->getProgress();j++){
            move(y+i,25+j);
            addch('*');
        }
        move(y+i,38);
        addstr("Hunger: ");
        addstr(to_string(creature->getHunger()).c_str());
        move(y+i,49);
        addstr(" Energy: ");
        addstr(to_string(creature->getEnergy()).c_str());


    }




}

void ConsoleManager::reprint() {
    usleep(40000);
    erase();
    printCreatureStats();
    refresh();

}

void ConsoleManager::TimeIsPassing() {
    while(ConsoleManager::survivalIsActive) {
        for (int i = 0; i < ConsoleManager::creatureList.size(); i++) {
            ConsoleManager::creatureList[i]->changeEnergyBy(-1);
            ConsoleManager::creatureList[i]->changeHungerBy(-1);
            ConsoleManager::creatureList[i]->CheckIfIsAlive();
        }
        sleep(1);
    }
}
