//
// Created by student on 2/1/21.
//

#ifndef OOPPROJECT_FRUIT_H
#define OOPPROJECT_FRUIT_H

#include "Entity.h"

class Fruit : public Entity {
public:
    int pointsGained;

    Fruit(int x, int y, std::string name, int pointsGained);
    void increaseAgeBy1() override;
    bool isDead() override;
    bool isEnemy() override;
    int getPointsGained() override;
    bool grow() override;
private:

};
#endif //OOPPROJECT_FRUIT_H
