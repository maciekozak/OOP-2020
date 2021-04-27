//
// Created by Dominik on 02/02/2021.
//

#ifndef OOPPROJECT_GAMELOGIC_H
#define OOPPROJECT_GAMELOGIC_H

#include "Snake.h"
#include "Map.h"
#include "Apple.h"
#include "Banana.h"
#include "Spike.h"
#include "memory"
#include <cstdlib>
#include <ctime>

class GameLogic {
private:
    unsigned int score;
    bool snakeDead;
    std::shared_ptr<Entity> entity;
    std::shared_ptr<Snake> snake;
    std::shared_ptr<Map> map;
    int getRandomNumber(unsigned int);
    bool isCollision();
public:
    GameLogic(unsigned int level, unsigned int width, unsigned int height);
    void prepareLevel(unsigned int level, unsigned int width, unsigned int height);
    void restartGame();
    void enterSecondLevel();
    void doOneFrame();
    void doOneFrame(Direction snakeDirection);
    void doLogic();
    void spawnEntity();
    std::shared_ptr<Entity> getEntity();
    std::shared_ptr<Snake> getSnake();
    std::shared_ptr<Map> getMap();
    unsigned int getScore();
    bool isSnakeAlive();
    bool gameEnd();
};

#endif //OOPPROJECT_GAMELOGIC_H
