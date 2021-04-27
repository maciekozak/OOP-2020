//
// Created by Dominik on 30/01/2021.
//

#ifndef OOPPROJECT_MAP_H
#define OOPPROJECT_MAP_H

constexpr unsigned int IMAGESIZE = 32;

class Map {
private:
    unsigned int level;
    unsigned int width;
    unsigned int height;

public:
    Map(unsigned int mapLevel, unsigned int mapWidth, unsigned int mapHeight);
    void setWall(int x, int y);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getLevel() const;
};

#endif //OOPPROJECT_MAP_H
