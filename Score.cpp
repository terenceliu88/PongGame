#include "Score.h"
#include <iostream>

Score::Score(char side) {
    myFont.loadFromFile("Fipps-Regular.otf");
    if(side == 'L') {
        scoreText.setFont(myFont);
        scoreText.setString(std::to_string(scorePoint));
        scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
        scoreText.setPosition(scoreText.getLocalBounds().width, scoreText.getLocalBounds().height);
    } else if(side == 'R') {
        scoreText.setFont(myFont);
        scoreText.setString(std::to_string(scorePoint));
        scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
        scoreText.setPosition(1200 - scoreText.getLocalBounds().width, scoreText.getLocalBounds().height);
    }
}

int Score::getScorePoint() {
    return scorePoint;
}
sf::Text Score::getScore() {
    return scoreText;
}
void Score::addPoint() {
    scorePoint++;
    scoreText.setString(std::to_string(scorePoint));
}
