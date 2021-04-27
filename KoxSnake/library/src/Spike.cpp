//
// Created by student on 2/1/21.
//

#include "Spike.h"
#include "Entity.h"

Spike::Spike(int x, int y, std::string name) : Entity(x, y, name) {

}

bool Spike::isEnemy() {
    return true;
}

int Spike::getPointsGained() {
    return 0;
}

bool Spike::isDead() {
    if ( lifetime == age ) {
        return true;
    } else return false;
}

int Spike::getLifetime() {
    return lifetime;
}

int Spike::getAge() {
    return age;
}

void Spike::increaseAgeBy1() {
    age++;
}

bool Spike::grow() {
    return false;
}
