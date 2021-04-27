//
// Created by Dominik on 30/01/2021.
//

#ifndef OOPPROJECT_SNAKE_H
#define OOPPROJECT_SNAKE_H

#include <stdexcept>
#include <deque>
#include <string>
#include <iostream>

class SnakeException : public std::logic_error {
public:
    explicit SnakeException(const std::string &message);
    virtual std::string message() const;
};
class DirectionException: public SnakeException
{
private:
    char direction;
public:
    explicit DirectionException(const std::string &message, char direction);
    char get_direction();
    virtual std::string message() const;
};

enum Direction {
    up = 'u',
    down = 'd',
    left = 'l',
    right = 'r'
};

struct Segment {
    int x, y;
};

class Snake {
private:
    std::deque<Segment> snakeBody;
    Direction currentDirection;
    Direction getOppositeDirection(Direction direction);
    Segment getCoordinatesForMovedSegment(Segment s, Direction direction);
    // used for initialization
    void createBody(int headX, int headY, unsigned int length, Direction headDirection);
public:
    Snake();
    Snake(int headX, int headY, unsigned int length, Direction headDirection);
    // move snake in specific Direction
    // if direction is opposite to current move in current direction
    void move(Direction direction);
    // move snake in currentDirection
    void move();
    Direction getTailDirection();
    void extend(int length);
    Direction getCurrentDirection()  const;
    Segment getSegment(int index);
    int getLength() const;
    void printStatus();

    std::deque<Segment> getOnlyBody();
};

#endif //OOPPROJECT_SNAKE_H
