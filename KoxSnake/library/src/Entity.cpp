//
// Created by student on 2/1/21.
//

#include "Entity.h"
#include <string>

Entity::Entity(int x, int y, std::string name) : x(x), y(y), name(name) {

}

int Entity::getX() {
    return x;
}

int Entity::getY() {
    return y;
}

std::string Entity::getName() {
    return name;
}

void Entity::setXY(int xx, int yy) {
    x = xx;
    y = yy;
}
