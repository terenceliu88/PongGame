#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Score.h"

class Ball {
private:
    sf::CircleShape ball;
    float xspeed = .5, yspeed = .5, speed = .71;
public:
    Ball(int width, int height);

    sf::CircleShape getBall();
    void moveBall(int height, int width, Paddle rightPad, Paddle leftPad, Score &rightScore, Score &leftScore);
};

#endif // BALL_H
