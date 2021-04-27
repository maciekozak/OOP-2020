//
// Created by student on 2/1/21.
//

#include "Fruit.h"
#include "Entity.h"

Fruit::Fruit(int x, int y, std::string name, int pointsGained) : Entity(x, y, name), pointsGained(pointsGained) {

}

bool Fruit::isEnemy() {
    return false;
}

int Fruit::getPointsGained() {
    return pointsGained;
}

void Fruit::increaseAgeBy1() {
    // empty, just temporarily it is here
}

bool Fruit::isDead() {
    // empty, just temporarily it is here
    return false;
}

bool Fruit::grow() {
    if(name == "apple") return true;
    else return false;
}
