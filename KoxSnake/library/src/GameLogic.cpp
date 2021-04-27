//
// Created by Dominik on 02/02/2021.
//

#include <GameLogic.h>

GameLogic::GameLogic(unsigned int level, unsigned int width, unsigned int height)
    : score(0), snakeDead(false) {
    prepareLevel(level, width, height);
}

void GameLogic::prepareLevel(unsigned int level, unsigned int width, unsigned int height) {
    // prepare map and snake
    map = std::make_shared<Map>(level, width, height);
    snake = std::make_shared<Snake>(width/2,height/2,5, Direction(down));
    spawnEntity();
}

void GameLogic::restartGame() {
    prepareLevel(1, map->getWidth(), map->getHeight());
    score = 0;
    snakeDead = false;
}

void GameLogic::enterSecondLevel() {
    prepareLevel(2, map->getWidth(), map->getHeight());
}

void GameLogic::doOneFrame() {
    snake->move();
    GameLogic::doLogic();
}

void GameLogic::doOneFrame(Direction snakeDirection) {
    snake->move(snakeDirection);
    GameLogic::doLogic();
}

bool GameLogic::isCollision() {
    auto head = snake->getSegment(0);
    auto borderX = map->getWidth() - 1;
    auto borderY = map->getHeight() - 1;
    // with wall
    if(!(borderX > head.x and head.x > 0) or !(borderY > head.y and head.y > 0)) {
        snakeDead = true;
        return true;
    }

    // with entity
    if((entity->getX() == head.x) and (entity->getY() == head.y)) {
         if(entity->isEnemy()){
          snakeDead = true;
          //   std::cout << "Collision: spiked... yikes" << std::endl;
          } else {
          //   std::cout << "Collision: om nom nom... +10 pts" << std::endl;
         }
        return true;
    }

    // with snake
    for( auto el : snake->getOnlyBody()) {
        if((el.x == head.x) and (el.y == head.y)) {
            snakeDead = true;
            return true;
        }
    }

    return false;
}

void GameLogic::doLogic() {
    //std::cout << gameEnd() << std::endl;
    if(GameLogic::isCollision()) {
        if(!(isSnakeAlive())) {
         //std::cout << "Game over!" << std::endl;

         } else {
            if(entity->grow()) {
                snake->extend(2);
                //std::cout << "Extend" << std::endl;
            }

            score+= entity->getPointsGained();
            spawnEntity();
            //std::cout << "Score: " << getScore() << std::endl;
        }
    }
    if(entity->isEnemy()){
        entity->increaseAgeBy1();
        if(entity->isDead()){
            spawnEntity();
        }
    }

}

int GameLogic::getRandomNumber(unsigned int repeats) {
    int number = 0;
    srand((unsigned) time(0) + repeats);
    number = rand();
    return number;
}

void GameLogic::spawnEntity() {
    unsigned int floorWidth = map->getWidth() - 2;
    unsigned int floorHeight = map->getHeight() - 2;
    int choose = 1 + getRandomNumber(0) % 10;
    int randY = 0;
    int randX = 0;
    auto head = snake->getSegment(0);

    // this solution preventing instant hitting spike (it doesn't care about fruits) is fast and doesn't create game freezing effect
    // it's executed mostly up to 3 times
    unsigned int counter = 0;
    do{
        counter++;
        //std::cout << "Randomize: " << counter << std::endl;
        randX = 1 + getRandomNumber(counter) % floorWidth;
        randY = 1 + getRandomNumber(counter) % (1+floorHeight/2) + getRandomNumber(counter) % floorHeight/2;
    } while((choose > 8) and (head.x < randX + 3) and (head.x > randX - 3) and (head.y < randY + 3) and (head.y > randY - 3));


    switch(choose){
        case 1 ... 6: {// 60% chance for apple
            Apple newApple(randX, randY, "apple", 10);
            entity = std::make_shared<Apple>(newApple);
//            std::cout << "Spawn: " + entity->getName() + " at: ";
//            std::cout << (int)entity->getX(); std::cout << " ";
//            std::cout << (int)entity->getY() << std::endl;
            break; }
        case 7 ... 8: {// 20% chance for banana
            Banana newBanana(randX, randY, "banana", 10);
            entity = std::make_shared<Banana>(newBanana);
//            std::cout << "Spawn: " + entity->getName() + " at: ";
//            std::cout << (int)entity->getX(); std::cout << " ";
//            std::cout << (int)entity->getY() << std::endl;
            break; }
        case 9 ... 10: {// 20% chance for spike
            Spike newSpike(randX, randY, "spike");
            entity = std::make_shared<Spike>(newSpike);
//            std::cout << "Spawn: " + entity->getName() + " at: ";
//            std::cout << (int)entity->getX(); std::cout << " ";
//            std::cout << (int)entity->getY() << std::endl;
            break; }
    }
}

std::shared_ptr<Entity> GameLogic::getEntity() {
    return entity;
}

std::shared_ptr<Snake> GameLogic::getSnake() {
    return snake;
}

std::shared_ptr<Map> GameLogic::getMap() {
    return map;
}

unsigned int GameLogic::getScore() {
    return score;
}

bool GameLogic::isSnakeAlive() {
    return !snakeDead;
}

bool GameLogic::gameEnd() {
    if(!(isSnakeAlive())){
        return true;
    } else {
        return false;
    }
}


