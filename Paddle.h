#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle {
private:
    sf::RectangleShape pad;
public:
    Paddle(char side);

    sf::RectangleShape getPad();
    void moveRPad();
    void moveLPad();
};

#endif // PADDLE_H
