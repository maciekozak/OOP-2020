//
// Created by student on 2/1/21.
//

#ifndef OOPPROJECT_SPIKE_H
#define OOPPROJECT_SPIKE_H

#include "Entity.h"

class Spike : public Entity {
public:
    Spike(int, int, std::string);

    bool isEnemy() override;
    int getPointsGained() override;
    bool isDead() override;
    void increaseAgeBy1() override;

    bool grow() override;
private:
    const int lifetime = 20; // 4 = approximately 1s
    int age = 0;

    int getLifetime();
    int getAge();


};
#endif //OOPPROJECT_SPIKE_H
