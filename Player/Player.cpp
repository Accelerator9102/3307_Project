#include "Player.h"

Player::Player(const std::map<unsigned int, unsigned int>& answerIDs,
               const Round* round = 0,
               const unsigned int& playerID = 0) {
    id = playerID;
    this->answerIDs = answerIDs;
    answerTime = 0;
    score = 0;
    currentAnswer = -1;
    this->round = round;
}

Player::~Player() { }

const unsigned int Player::getPlayerID() const {
    return id;
}

const int Player::getScore() const {
    return score;
}

const int Player::getAnswer() const {
    return answer;
}

void Player::addScore(const unsigned int& amount = 1) {
    score += amount;
}

void Player::resetScore() {
    score = 0;
}

const bool Player::isAnswerReady() const {
    return answer == -1;
}

void Player::setRound(const Round* round) {
    this->round = round;
    answer = -1;
}

void Player::notify(const int& inputID) {
    currentAnswer = answerIDs.at(inputID);
    round->submitAnswer(id, currentAnswer);
}

const bool operator<(const Player& other) {
    return this->getScore() < other.getScore();
}
