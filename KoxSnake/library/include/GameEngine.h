//
// Created by Dominik on 25/01/2021.
//

#ifndef OOPPROJECT_GAMEENGINE_H
#define OOPPROJECT_GAMEENGINE_H
#include <iostream>
#include <memory>
#include "Renderer.h"
#include "RendererSfml.h"

class GameEngine {
private:
    std::shared_ptr<GameLogic> gameLogic;
    std::shared_ptr<Renderer> myRenderer;
public:
    GameEngine();
    void startGame(unsigned int level, unsigned int width, unsigned int height);
};

#endif //OOPPROJECT_GAMEENGINE_H
