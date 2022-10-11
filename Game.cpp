#include "Game.h"

Game::Game() {
    myFont.loadFromFile("Fipps-Regular.otf");

    welcomeText.setFont(myFont);
    welcomeText.setString("WELCOME TO PONG GAME");
    welcomeText.setOrigin(welcomeText.getLocalBounds().width / 2, welcomeText.getLocalBounds().height / 2);
    welcomeText.setPosition(width / 2, height / 2);

    instructionsText.setFont(myFont);
    instructionsText.setString("PRESS SPACEBAR TO START GAME");
    instructionsText.setOrigin(instructionsText.getLocalBounds().width / 2, instructionsText.getLocalBounds().height / 2);
    instructionsText.setPosition(width / 2, height / 2 + 100);

    leftWinText.setFont(myFont);
    leftWinText.setString("PLAYER LEFT WINS");
    leftWinText.setOrigin(leftWinText.getLocalBounds().width / 2, leftWinText.getLocalBounds().height / 2);
    leftWinText.setPosition(width / 2, height / 2);

    rightWinText.setFont(myFont);
    rightWinText.setString("PLAYER RIGHT WINS");
    rightWinText.setOrigin(rightWinText.getLocalBounds().width / 2, rightWinText.getLocalBounds().height / 2);
    rightWinText.setPosition(width / 2, height / 2);
}

void Game::game() {
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(width, height), "Pong Game");

    // Load a sprite to display
    Paddle rightPad('R');
    Paddle leftPad('L');
    Ball gameBall(width, height);
    Score leftScore('L');
    Score rightScore('R');

    // Start the game loop
    while (app.isOpen()) {
        // Process events
        sf::Event event;
        while (app.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                app.close();
            }
        }

        // Game Logic
        if(gameState == 1) {
            welcomeScreen(app);
        } else if (gameState == 2) {
            play(app, rightPad, leftPad, gameBall, leftScore, rightScore);
        } else if (gameState == 3) {
            endScreen(app, leftScore, rightScore);
        }

        // Update the window
        app.display();
    }
}
void Game::welcomeScreen(sf::RenderWindow &app) {
    app.clear();

    app.draw(welcomeText);
    app.draw(instructionsText);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        gameState = 2;
    }
}

void Game::play(sf::RenderWindow &app, Paddle &rightPad, Paddle &leftPad, Ball &gameBall, Score &leftScore, Score &rightScore) {
    rightPad.moveRPad();
    leftPad.moveLPad();
    gameBall.moveBall(height, width, rightPad, leftPad, rightScore, leftScore);

    app.clear();

    app.draw(rightPad.getPad());
    app.draw(leftPad.getPad());
    app.draw(gameBall.getBall());
    app.draw(leftScore.getScore());
    app.draw(rightScore.getScore());
    if(leftScore.getScorePoint() == 10 || rightScore.getScorePoint() == 10) {
        gameState = 3;
    }
}
void Game::endScreen(sf::RenderWindow &app, Score leftScore, Score rightScore) {
    app.clear();

    if(leftScore.getScorePoint() == 10) {
        app.draw(leftWinText);
    } else if (rightScore.getScorePoint() == 10) {
        app.draw(rightWinText);
    }
}
