//
// Created by Dominik on 30/01/2021.
//

#include <Map.h>

Map::Map(unsigned int mapLevel, unsigned int mapWidth, unsigned int mapHeight)
: level(mapLevel), width(mapWidth), height(mapHeight) {

}

void Map::setWall(int x, int y) {

}

unsigned int Map::getWidth() const {
    return width;
}

unsigned int Map::getHeight() const {
    return height;
}

unsigned int Map::getLevel() const {
    return level;
}

