//
// Created by Dominik on 29/01/2021.
//

#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<GameLogic> inputGameLogic) : gameLogic(inputGameLogic){

}

void Renderer::doGameLogic() {
    gameLogic->doOneFrame();
}

void Renderer::doGameLogic(Direction snakeDirection) {
    gameLogic->doOneFrame(snakeDirection);
}
