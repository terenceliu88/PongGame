#include "Paddle.h"

Paddle::Paddle(char side)
{
    if(side == 'R'){
        pad.setSize(sf::Vector2f(15, 100));
        pad.setOrigin(7.5, 50);
        pad.setPosition(1200 - 30, 800 / 2);
        pad.setFillColor(sf::Color::Magenta);
    } else if(side == 'L'){
        pad.setSize(sf::Vector2f(15, 100));
        pad.setOrigin(7.5, 50);
        pad.setPosition(30, 800 / 2);
        pad.setFillColor(sf::Color::Magenta);
    }
}

sf::RectangleShape Paddle::getPad(){
    return pad;
}
void Paddle::moveRPad(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pad.getPosition().y > 50) {
        pad.move(0, -.5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pad.getPosition().y < (800 - 50)) {
        pad.move(0, .5);
    }
}
void Paddle::moveLPad(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pad.getPosition().y > 50) {
        pad.move(0, -.5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pad.getPosition().y < (800 - 50)) {
        pad.move(0, .5);
    }
}

