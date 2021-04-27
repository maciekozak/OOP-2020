//
// Created by Dominik on 30/01/2021.
//
#include <Snake.h>

SnakeException::SnakeException(const std::string &message) : logic_error(message) {

};

std::string DirectionException::message() const {
    return what();
}

std::string SnakeException::message() const {
    return std::string();
}

DirectionException::DirectionException(const std::string &message, char direction)
    : SnakeException(message), direction(direction) {
}

char DirectionException::get_direction() {
    return direction;
}

Snake::Snake() {
    createBody(0,0,2,Direction(down));
}

Snake::Snake(int headX, int headY, unsigned int length, Direction headDirection) {
    createBody(headX, headY, length, headDirection);
}

Direction Snake::getOppositeDirection(Direction direction) {
    switch (direction) {
        case Direction(up):
            return Direction(down);
            break;
        case Direction(down):
            return Direction(up);
            break;
        case Direction(left):
            return Direction(right);
            break;
        case Direction(right):
            return Direction(left);
            break;
    }
}

Segment Snake::getCoordinatesForMovedSegment(Segment s, Direction direction) {
    // we will create snake in given direction so firstly we calculate offset for next body parts after head
    int xModifier, yModifier;
    // assume that left right corner is 0, 0
    switch (direction) {
        case 'u':
            xModifier = 0;
            yModifier = -1;
            break;
        case 'd':
            xModifier = 0;
            yModifier = 1;
            break;
        case 'l':
            xModifier = -1;
            yModifier = 0;
            break;
        case 'r':
            xModifier = 1;
            yModifier = 0;
            break;
        default:
            throw DirectionException("Wrong direction in function createBody: ", direction);
    }
    Segment newSegment;
    newSegment.x = s.x + xModifier;
    newSegment.y = s.y + yModifier;
    return newSegment;
}

void Snake::createBody(int headX, int headY, unsigned int length, Direction headDirection) {
    if (length < 2) throw SnakeException("Can't create snake that small!");
    Segment base;
    base.x = 0;
    base.y = 0;
    // calculate offsets for each new segment, that means if we provide direction left we will get x = -1 and y = 0
    base = getCoordinatesForMovedSegment(base, headDirection);
    Segment temp;
    for (int i = 0; i < length; i++) {
        temp.x = headX + i * base.x;
        temp.y = headY + i * base.y;
        snakeBody.push_back(temp);
    }
    currentDirection = getOppositeDirection(headDirection);
}

void Snake::move(Direction direction) {
    // snake cannot move into itself - it cannot go back
    if ( direction != currentDirection) {
        if (currentDirection == 'u' and direction == 'd'
        or currentDirection == 'd' and direction == 'u'
        or currentDirection == 'l' and direction == 'r'
        or currentDirection == 'r' and direction == 'l') {
            // just set direction to previous direction if one wants to go back
            direction = currentDirection;
        }
    }
    Segment newHead = getCoordinatesForMovedSegment(snakeBody.front(), direction);
    // we "move" our head
    snakeBody.push_front(newHead);
    // remove last element, as the tail is now one step further
    snakeBody.pop_back();
    // update current direction
    currentDirection = direction;
}

void Snake::move() {
    move(currentDirection);
}

Direction Snake::getTailDirection() {
    Direction direction;
    Segment tail = snakeBody.back();
    // element/snake's segment before tail
    Segment almostTail = getSegment(snakeBody.size() - 2);
    // if they lie in the same row
    if (tail.y == almostTail.y ) {
        if (tail.x < almostTail.x) {
            direction = left;
        } else {
            direction = right;
        }
    } else {
        if (tail.y < almostTail.y) {
            direction = up;
        } else {
            direction = down;
        }
    }
    return direction;
}

void Snake::extend(int length) {
    // discover the direction relative to the tail where the new tail will be
    Direction direction = getTailDirection();
    for (int i = 0; i < length; i++) {
        Segment newTail = getCoordinatesForMovedSegment(getSegment(snakeBody.size() - 1), direction);
        snakeBody.push_back(newTail);
    }
}

Direction Snake::getCurrentDirection() const {
    return currentDirection;
}

Segment Snake::getSegment(int index) {
    return snakeBody[index];
}

int Snake::getLength() const {
    return snakeBody.size();
}

void Snake::printStatus() {
    for (int i = 0; i < getLength(); i++) {
        std::cout << i << ": ";
        std::cout << " x: " << getSegment(i).x;
        std::cout << " y: " << getSegment(i).y;
        std::cout << " tail direction: " << char(getTailDirection());
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

std::deque<Segment> Snake::getOnlyBody() {
    std::deque<Segment> result;
    for(int i=1;i<getLength();i++){
        result.push_back(getSegment(i));
    }
    return result;
}
