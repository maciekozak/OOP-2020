//
// Created by Dominik on 29/01/2021.
//

#include "RendererSfml.h"

RendererException::RendererException(const std::string &message) : logic_error(message) {

};

std::string ImageLoadingException::message() const {
    return what();
}

std::string RendererException::message() const {
    return std::string();
}

ImageLoadingException::ImageLoadingException(const std::string &message)
        : RendererException(message) {
}

FontLoadingException::FontLoadingException(const std::string &message)
        : RendererException(message) {
}

std::string FontLoadingException::message() const {
    return what();
}

RendererSfml::RendererSfml(std::shared_ptr<GameLogic> inputGameLogic) : Renderer(inputGameLogic) {

}

RendererSfml::~RendererSfml() {

}

void RendererSfml::loadAllTextures() {
    // snake
    // head
    if (!(snakeHeadTexture.loadFromFile("assets/snake/head.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    snakeHeadImage.setTexture(snakeHeadTexture);
    // body
    if (!(snakeBodyTexture.loadFromFile("assets/snake/body.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    snakeBodyImage.setTexture(snakeBodyTexture);
    // tail
    if (!(snakeTailTexture.loadFromFile("assets/snake/tail.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    snakeTailImage.setTexture(snakeTailTexture);
    // level
    std::string pathToLevel = "assets/levels/" + std::to_string(gameLogic->getMap()->getLevel()) + "/";
    if (!(levelBackgroundTexture.loadFromFile(pathToLevel + "floor_1.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    levelBackgroundImage.setTexture(levelBackgroundTexture);
    // corner
    if (!(levelBorderCornerTexture.loadFromFile(pathToLevel + "border/border_corner.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    levelBorderCornerImage.setTexture(levelBorderCornerTexture);
    // border
    if (!(levelBorderTexture.loadFromFile(pathToLevel + "border/border.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    levelBorderImage.setTexture(levelBorderTexture);
    // border special
    if (!(levelBorderSpecialDownTexture.loadFromFile(pathToLevel + "border/border_special_down.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    levelBorderSpecialDownImage.setTexture(levelBorderSpecialDownTexture);
    // border special
    if (!(levelBorderSpecialLeftTexture.loadFromFile(pathToLevel + "border/border_special_left.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    levelBorderSpecialLeftImage.setTexture(levelBorderSpecialLeftTexture);
    // border special
    if (!(levelBorderSpecialUpTexture.loadFromFile(pathToLevel + "border/border_special_up.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    levelBorderSpecialUpImage.setTexture(levelBorderSpecialUpTexture);
    // border special
    if (!(levelBorderSpecialRightTexture.loadFromFile(pathToLevel + "border/border_special_right.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    levelBorderSpecialRightImage.setTexture(levelBorderSpecialRightTexture);
    // spike
    if (!(spikeTexture.loadFromFile(pathToLevel + "spike.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    spikeImage.setTexture(spikeTexture);
    // apple
    if (!(appleTexture.loadFromFile("assets/fruits/apple.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    appleImage.setTexture(appleTexture);
    // banana
    if (!(bananaTexture.loadFromFile("assets/fruits/banana.png"))) {
        throw ImageLoadingException("Image file is missing.");
    }
    bananaImage.setTexture(bananaTexture);
}

void RendererSfml::renderGameOver(unsigned int score) {
    sf::Text text;
    text.setFont(gameFont); // font is a sf::Font
    // set the string to display
    std::string gameOverText = "Game over!\nYour score: " + std::to_string(score) + '\n' + "'r' - restart" + '\n' + "'esc' - quit";
    text.setString(gameOverText);
    text.setCharacterSize(IMAGESIZE * 1.5); // in pixels, not points
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(IMAGESIZE * 2, IMAGESIZE);
    window.draw(text);
}

void RendererSfml::renderSecondLevelWelcomeScreen() {
    sf::Text text;
    text.setFont(gameFont); // font is a sf::Font
    // set the string to display
    std::string gameOverText = "Get ready for the final level!";
    text.setString(gameOverText);
    text.setCharacterSize(IMAGESIZE * 1.5); // in pixels, not points
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(IMAGESIZE * 2, IMAGESIZE);
    window.draw(text);
}

void RendererSfml::renderEverything(Map& map, Snake& snake) {
    renderMap(map);
    renderEntity(*gameLogic->getEntity());
    renderSnake(snake);
    renderScore(gameLogic->getScore());
}

void RendererSfml::renderScore(int score) {
    sf::Text text;
    text.setFont(gameFont); // font is a sf::Font
    // set the string to display
    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize(IMAGESIZE - 2); // in pixels, not points
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Regular);
    text.setPosition(IMAGESIZE, -8);
    window.draw(text);
}

void RendererSfml::renderMap(Map& map) {
    // render inside part
    for (int x = 1; x < map.getWidth() - 1; x++) {
        for (int y = 1; y < map.getHeight() - 1; y++) {
            levelBackgroundImage.setPosition(x * IMAGESIZE,y * IMAGESIZE);
            window.draw(levelBackgroundImage);
        }
    }
    // render the frame
    // transform - bring back the rotated image to match the squares
    sf::Transform t;
    t.translate(IMAGESIZE/2,IMAGESIZE/2);
    levelBorderCornerImage.setOrigin(IMAGESIZE/2,IMAGESIZE/2);
    levelBorderCornerImage.setPosition(0, 0);
    window.draw(levelBorderCornerImage, t);
    levelBorderCornerImage.setPosition((map.getWidth() - 1) * IMAGESIZE, 0 * IMAGESIZE);
    levelBorderCornerImage.rotate(90.0);
    window.draw(levelBorderCornerImage, t);
    levelBorderCornerImage.setPosition((map.getWidth() - 1) * IMAGESIZE, (map.getHeight() - 1) * IMAGESIZE);
    levelBorderCornerImage.rotate(90.0);
    window.draw(levelBorderCornerImage, t);
    levelBorderCornerImage.setPosition(0, (map.getHeight() - 1) * IMAGESIZE);
    levelBorderCornerImage.rotate(90.0);
    window.draw(levelBorderCornerImage, t);
    levelBorderCornerImage.rotate(90.0);
    // the borders
    levelBorderImage.setOrigin(IMAGESIZE/2,IMAGESIZE/2);
    for (int x = 1; x < map.getWidth() - 1; x++) {
        levelBorderImage.setPosition(x * IMAGESIZE,0 * IMAGESIZE);
        window.draw(levelBorderImage, t);
    }
    levelBorderImage.rotate(90.0);
    for (int y = 1; y < map.getHeight() - 1; y++) {
        levelBorderImage.setPosition((map.getWidth() - 1) * IMAGESIZE,y * IMAGESIZE);
        window.draw(levelBorderImage, t);
    }
    levelBorderImage.rotate(90.0);
    for (int x = 1; x < map.getWidth() - 1; x++) {
        levelBorderImage.setPosition(x * IMAGESIZE,(map.getHeight() - 1) * IMAGESIZE);
        window.draw(levelBorderImage, t);
    }
    levelBorderImage.rotate(90.0);
    for (int y = 1; y < map.getHeight() - 1; y++) {
        levelBorderImage.setPosition(0 * IMAGESIZE,y * IMAGESIZE);
        window.draw(levelBorderImage, t);
    }
    levelBorderImage.rotate(90.0); // so it return to default position
    // special blocks
    levelBorderSpecialUpImage.setPosition((map.getWidth() - 4) * IMAGESIZE,0 * IMAGESIZE);
    window.draw(levelBorderSpecialUpImage);
    levelBorderSpecialDownImage.setPosition(IMAGESIZE * 3,(map.getHeight() - 1) * IMAGESIZE);
    window.draw(levelBorderSpecialDownImage);
    levelBorderSpecialRightImage.setPosition(IMAGESIZE * (map.getWidth() - 1),(map.getHeight() - 5) * IMAGESIZE);
    window.draw(levelBorderSpecialRightImage);
    levelBorderSpecialLeftImage.setPosition(IMAGESIZE * 0,4 * IMAGESIZE);
    window.draw(levelBorderSpecialLeftImage);
}

float RendererSfml::getRotationAngle(Direction desiredDirection) {
    float rotation = 0.0;
    switch (desiredDirection) {
        case Direction(left):
            rotation = 90.0;
            break;
        case Direction(up):
            rotation = 180.0;
            break;
        case Direction(right):
            rotation = -90.0;
            break;
        case Direction(down):
            rotation = 0.0;
            break;
    }
    return rotation;
}

void RendererSfml::renderSnake(Snake& snake) {
    snakeHeadImage.setPosition(snake.getSegment(0).x * IMAGESIZE, snake.getSegment(0).y * IMAGESIZE);
    sf::Sprite snakeHeadImageCopy = snakeHeadImage;
    // rotate in relation to the centre
    snakeHeadImageCopy.setOrigin(IMAGESIZE/2,IMAGESIZE/2);
    snakeHeadImageCopy.rotate(getRotationAngle(snake.getCurrentDirection()));
    // bring back the rotated head image to match the squares
    sf::Transform t;
    t.translate(IMAGESIZE/2,IMAGESIZE/2);
    window.draw(snakeHeadImageCopy, t);
    for (int length = 1; length < snake.getLength() - 1; length++) {
        snakeBodyImage.setPosition(snake.getSegment(length).x * IMAGESIZE, snake.getSegment(length).y * IMAGESIZE);
        window.draw(snakeBodyImage);
    }
    // rendering the tail
    snakeTailImage.setPosition(snake.getSegment(snake.getLength()-1).x * IMAGESIZE, snake.getSegment(snake.getLength()-1).y * IMAGESIZE);
    sf::Sprite snakeTailImageCopy = snakeTailImage;
    snakeTailImageCopy.setOrigin(IMAGESIZE/2,IMAGESIZE/2);
    snakeTailImageCopy.rotate(getRotationAngle(snake.getTailDirection()));
    // the translation was already calculated before
    window.draw(snakeTailImageCopy, t);
}

void RendererSfml::renderEntity(Entity& entity) {
    std::string choose = entity.getName();

    if (choose == "apple") {
            appleImage.setPosition(entity.getX() * IMAGESIZE, entity.getY() * IMAGESIZE);
            window.draw(appleImage);
        } else if (choose == "spike") {
            spikeImage.setPosition(entity.getX() * IMAGESIZE, entity.getY() * IMAGESIZE);
            window.draw(spikeImage);
        } else if (choose == "banana") {
            bananaImage.setPosition(entity.getX() * IMAGESIZE, entity.getY() * IMAGESIZE);
            window.draw(bananaImage);
        }
}

void RendererSfml::gameMainLoop() {
    //sf::RenderWindow window; moved to private attribute
    window.create(
            sf::VideoMode((*gameLogic->getMap()).getWidth() * IMAGESIZE, (*gameLogic->getMap()).getHeight() * IMAGESIZE),
            "KoxSnake");

    window.setKeyRepeatEnabled(false);
    // important - load all textures
    loadAllTextures();
    loadGameFonts();

    //declare before loop, if you dont, elapsed time constantly gets set to 0
    sf::Time  dt; // delta time
    sf::Time  elapsedTime;
    sf::Clock clock;

    while (window.isOpen()) {
        elapsedTime += clock.getElapsedTime();
        dt = clock.getElapsedTime();
        clock.restart();

        if (elapsedTime.asMilliseconds() > timePerFrameInMiliseconds)
        {
            // if player is still alive do logic
            if ( !(gameLogic->gameEnd()) ) {
                if (!keypressQueue.empty()) {
                    gameLogic->doOneFrame(keypressQueue.front());
                    // pop key as we executed the input
                    keypressQueue.pop_front();
                } else {
                    // continue moving in the same direction
                    gameLogic->doOneFrame();
                }
                renderEverything((*gameLogic->getMap()), (*gameLogic->getSnake()));
                window.display();
            } else {
                // check if user wants to start a new game by clicking any arrow
                if (isRestartKeyPressed()) {
                    // pop key used to activate a new game
                    keypressQueue.clear();
                    // set up new game
                    gameLogic->restartGame();
                    // revert back to level one texture
                    loadAllTextures();
                }
                //
                renderEverything((*gameLogic->getMap()), (*gameLogic->getSnake()));
                renderGameOver(gameLogic->getScore());
                window.display();
            }
            // after doing the logic check if user can enter next level
            if(gameLogic->getScore() > 100 and gameLogic->getMap()->getLevel() == 1) {
                gameLogic->enterSecondLevel();
                renderSecondLevelWelcomeScreen();
                window.display();
                sf::sleep(sf::milliseconds(2000));
                // load new textures
                loadAllTextures();
                renderEverything((*gameLogic->getMap()), (*gameLogic->getSnake()));
                window.display();
            }
            elapsedTime = sf::milliseconds(0); // reset frame counter
        }
        if (!(gameLogic->gameEnd())) {
            handleInput();
        }
    }
}

void RendererSfml::handleInput() {
    sf::Event event{};

    while (window.pollEvent(event)) {
        // Window closed
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Handle Keyboard Input
        if (event.type == sf::Event::KeyPressed) {
            // Quit
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
    } // END while pollEvent
    // Directions
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        addKeypressToQueue(Direction(up));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        addKeypressToQueue(Direction(down));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        addKeypressToQueue(Direction(left));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        addKeypressToQueue(Direction(right));
    }
}

bool RendererSfml::isRestartKeyPressed() {
    sf::Event event{};

    while (window.pollEvent(event)) {
        // Window closed
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Handle Keyboard Input
        if (event.type == sf::Event::KeyPressed) {
            // Quit
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
    } // END while pollEvent
    // Directions
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::R) ) {
        return true;
    }
    return false;
}

void RendererSfml::addKeypressToQueue(Direction direction) {
    if (keypressQueue.empty()) {
        keypressQueue.emplace_back(direction);
    }
    else {
        if (keypressQueue.back() != direction) {
            keypressQueue.emplace_back(direction);
        }
    }
}

void RendererSfml::loadGameFonts() {
    if (!gameFont.loadFromFile("assets/fonts/VT323-Regular.ttf"))
    {
        throw FontLoadingException("Font file is missing.");
    }
}
