//
// Created by Dominik on 29/01/2021.
//

#ifndef OOPPROJECT_RENDERERSFML_H
#define OOPPROJECT_RENDERERSFML_H

#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include "deque"

class RendererSfml : public Renderer {
public:
    RendererSfml(std::shared_ptr<GameLogic> inputGameLogic);
    ~RendererSfml();
    void gameMainLoop();
private:
    sf::RenderWindow window;
    // textures default rotation (if the snake's head is facing down it is equal to down)
    Direction defaultTextureRotation = Direction(down);
    float getRotationAngle(Direction desiredDirection);
    // all textures
    sf::Texture snakeHeadTexture;
    sf::Sprite snakeHeadImage;
    sf::Texture snakeBodyTexture;
    sf::Sprite snakeBodyImage;
    sf::Texture snakeTailTexture;
    sf::Sprite snakeTailImage;
    // background
    sf::Texture levelBackgroundTexture;
    sf::Sprite levelBackgroundImage;
    // borders
    sf::Texture levelBorderTexture;
    sf::Sprite levelBorderImage;
    sf::Texture levelBorderCornerTexture;
    sf::Sprite levelBorderCornerImage;
    sf::Texture levelBorderSpecialDownTexture;
    sf::Sprite levelBorderSpecialDownImage;
    sf::Texture levelBorderSpecialLeftTexture;
    sf::Sprite levelBorderSpecialLeftImage;
    sf::Texture levelBorderSpecialUpTexture;
    sf::Sprite levelBorderSpecialUpImage;
    sf::Texture levelBorderSpecialRightTexture;
    sf::Sprite levelBorderSpecialRightImage;
    // spike
    sf::Texture spikeTexture;
    sf::Sprite spikeImage;
    // apple
    sf::Texture appleTexture;
    sf::Sprite appleImage;
    // banana
    sf::Texture bananaTexture;
    sf::Sprite bananaImage;
    void loadAllTextures();
    // fonts
    sf::Font gameFont;
    void loadGameFonts();
    // speed of the game
    int timePerFrameInMiliseconds = 150;
    // key handling
    std::deque<Direction> keypressQueue; // queue for direction key presses
    void handleInput();
    void addKeypressToQueue(Direction direction);
    //bool isRestartKeyPressed = false;
    bool isRestartKeyPressed();
    //
    void renderEverything(Map& map, Snake& snake);
    void renderScore(int score);
    void renderMap(Map& map);
    void renderSnake(Snake& snake);
    void renderGameOver(unsigned int score);
    void renderEntity(Entity& entity);
    void renderSecondLevelWelcomeScreen();
};
#endif //OOPPROJECT_RENDERERSFML_H
