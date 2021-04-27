//
// Created by Dominik on 29/01/2021.
//

#ifndef OOPPROJECT_RENDERER_H
#define OOPPROJECT_RENDERER_H

#include "Map.h"
#include "Snake.h"
#include "Entity.h"
#include "GameLogic.h"

class RendererException : public std::logic_error {
public:
    explicit RendererException(const std::string &message);
    virtual std::string message() const;
};
class ImageLoadingException : public RendererException
{
public:
    explicit ImageLoadingException(const std::string &message);
    virtual std::string message() const;
};
class FontLoadingException : public RendererException
{
public:
    explicit FontLoadingException(const std::string &message);
    virtual std::string message() const;
};

class Renderer {
public:
    Renderer(std::shared_ptr<GameLogic> inputGameLogic);
    virtual void gameMainLoop() = 0;
protected:
    std::shared_ptr<GameLogic> gameLogic;
private:
    virtual void renderEverything(Map& map, Snake& snake) = 0;
    virtual void renderScore(int score) = 0;
    virtual void renderMap(Map& map) = 0;
    virtual void renderSnake(Snake& snake) = 0;
    virtual void renderEntity(Entity& entity) = 0;
    virtual void renderGameOver(unsigned int score) = 0;
    virtual void renderSecondLevelWelcomeScreen() = 0;
    virtual void doGameLogic();
    virtual void doGameLogic(Direction snakeDirection);
};

#endif //OOPPROJECT_RENDERER_H
