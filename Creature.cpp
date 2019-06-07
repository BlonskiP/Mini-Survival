//
// Created by wilk on 07.06.19.
//

#include <iostream>
#include "Creature.h"
using namespace std;

int Creature::getHunger() {
    return this->hunger;
}

int Creature::getEnergy() {
    return this->energy;
}

void Creature::changeHungerBy(int change) {
    this->hunger+=change;
    if(hunger>maxHunger)hunger=maxHunger;

}

void Creature::changeEnergyBy(int change) {

    this->energy+=change;
    if(energy>maxEnergy)energy=maxEnergy;

}

bool Creature::CheckIfIsAlive() {
    if(this->energy<0 || this->hunger<0 )
        isAlive=false;
    return isAlive;
}

Creature::Creature(string name) {

    isAlive=true;
    this->name=name;
    hunger=100;
    energy=100;
    creatureThread=thread(&Creature::Survive,this);


}

void Creature::Survive() {
    while(isAlive){
        cout<<"I'm alive";
    }
}

