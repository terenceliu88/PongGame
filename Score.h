#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>

class Score {
private:
    sf::Font myFont;
    int scorePoint = 0;
    sf::Text scoreText;
public:
    Score(char side);

    int getScorePoint();
    sf::Text getScore();
    void addPoint();
};

#endif // SCORE_H
