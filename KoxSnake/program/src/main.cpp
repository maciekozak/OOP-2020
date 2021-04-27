#include <iostream>
#include "GameEngine.h"
using namespace std;

int main() {
    std::cout << "*-------------------------------------------------------------*" << std::endl;
    std::cout << "| Created by Dominik Czerwoniuk 230446 and Maciej Kopa 230451 |" << std::endl;
    std::cout << "*-------------------------------------------------------------*" << std::endl;
    GameEngine noodleGame;
    noodleGame.startGame(1, 24, 24);
    return 0;
}