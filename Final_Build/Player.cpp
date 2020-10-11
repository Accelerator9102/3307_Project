#include "Player.h"

/// This constructor initializes variables.
Player::Player(const std::map<unsigned int, unsigned int>& answerIDs,
               const Round* round,
               const unsigned int& playerID) {
    id = playerID;
    this->answerIDs = answerIDs;
    score = 0;
    currentAnswer = -1;
    is_answering = false;
    this->round = round;
}

/// Destructor.
Player::~Player() { }

/// This method retrieves the player's ID.
const unsigned int Player::getPlayerID() const {
    return id;
}

/// This method retrieves the player's score.
const int Player::getScore() const {
    return score;
}

/// This method retrieves the player's current selected answer.
const int Player::getAnswer() const {
    return currentAnswer;
}

/// This method increases the score of the player if they are in the correct state.
void Player::addScore(const unsigned int amount) const {
    if (is_answering) {
        score += amount;
        is_answering = false;
    }
}

/// This method resets a player's score to 0.
void Player::resetScore() {
    score = 0;
}

/// This method checks if a player has answered yet or not.
const bool Player::isAnswerReady() const {
    return currentAnswer != -1;
}

/// This method sets the player's round to be a new one and sets their selected answer back to default.
void Player::setRound(const Round* round) {
    this->round = round;
    currentAnswer = -1;
    is_answering = true;
}

/// This method receives input from an input object and stores the given answer.
void Player::notify(const unsigned int& inputID) const {
    if (is_answering) {
        //std::cout << "Looking for: " << inputID << std::endl;
        currentAnswer = answerIDs.at(inputID);
        //std::cout << "Found! Sending " << currentAnswer << std::endl;
        round->submitAnswer(id, currentAnswer);
    }
}

//
const bool Player::operator<(const Player& other) const {
    return this->getScore() < other.getScore();
}
