#include <cmath>
#include "Ball.h"

Ball::Ball(int width, int height) {
    ball.setRadius(15);
    ball.setOrigin(15, 15);
    ball.setPosition(width / 2, height / 2);
    ball.setFillColor(sf::Color::Cyan);
}

sf::CircleShape Ball::getBall() {
    return ball;
}
void Ball::moveBall(int height, int width, Paddle rightPad, Paddle leftPad, Score &rightScore, Score &leftScore) {
    ball.move(xspeed, yspeed);

    if(ball.getPosition().y > height - 15 || ball.getPosition().y < 15) {
        yspeed *= -1;
    }
    if(ball.getPosition().x > width - 15) {
        ball.setPosition(60, height / 2);
        leftScore.addPoint();
    }
    if(ball.getPosition().x < 15) {
        ball.setPosition(width - 60, height / 2);
        rightScore.addPoint();
    }
    if(rightPad.getPad().getGlobalBounds().intersects(ball.getGlobalBounds())) {
        yspeed = (ball.getPosition().y - rightPad.getPad().getPosition().y) / 65.0 * (speed - .2);
        xspeed = sqrt(speed * speed - yspeed * yspeed) * -1;
    }
    if(leftPad.getPad().getGlobalBounds().intersects(ball.getGlobalBounds())) {
        yspeed = (ball.getPosition().y - leftPad.getPad().getPosition().y) / 65.0 * (speed - .2);
        xspeed = sqrt(speed * speed - yspeed * yspeed);
    }
}
