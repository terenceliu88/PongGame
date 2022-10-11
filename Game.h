#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"

using namespace std;

class Game {
private:
    int width = 1200, height = 800;
    int gameState = 1;
    sf::Font myFont;
    sf::Text welcomeText;
    sf::Text instructionsText;
    sf::Text leftWinText;
    sf::Text rightWinText;
public:
    Game();

    void game();
    void welcomeScreen(sf::RenderWindow &app);
    void play(sf::RenderWindow &app, Paddle &rightPad, Paddle &leftPad, Ball &gameBall, Score &leftScore, Score &RightScore);
    void endScreen(sf::RenderWindow &app, Score leftScore, Score rightScore);
};

#endif // GAME_H
