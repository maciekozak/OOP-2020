//
// Created by student on 2/1/21.
//

#ifndef OOPPROJECT_ENTITY_H
#define OOPPROJECT_ENTITY_H

#include <string>

class Entity {
public:
    Entity(int x, int y, std::string name);
    int getX();
    int getY();
    std::string getName();
    void setXY(int x,int y);

    virtual bool isEnemy()=0;
    virtual int getPointsGained()=0;
    virtual void increaseAgeBy1()=0;
    virtual bool isDead()=0;
    virtual bool grow() = 0;
protected:
    int x;
    int y;
    std::string name;

};






#endif //OOPPROJECT_ENTITY_H
