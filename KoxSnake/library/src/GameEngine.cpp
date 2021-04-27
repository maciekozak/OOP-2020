//
// Created by Dominik on 25/01/2021.
//
#include "GameEngine.h"

GameEngine::GameEngine() {

}

void GameEngine::startGame(unsigned int level, unsigned int width, unsigned int height) {
    try {
        // create logic
        gameLogic = std::make_shared<GameLogic>(level, width, height);
        // initialize renderer, give it logic
        myRenderer = std::make_shared<RendererSfml>(gameLogic);
        // run main loop
        myRenderer->gameMainLoop();
    } catch (const ImageLoadingException& e) {
        std::cerr << e.what();

    } catch (const FontLoadingException& e) {
        std::cerr << e.what();
    }
}


