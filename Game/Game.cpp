#include "Game.h"

Game* Game::instance = NULL;

Game::Game() {
    total_rounds = 10;
    round_length = 30;
    point_value = 100;
    time_bonus = 100;
    round_number = 0;
    player_number = 0;
    time_between_rounds = 3;
    between_rounds_timer = TimeManager::getInstance().addTimer(time_between_rounds, false);
}

Game::~Game() { }

Game& Game::getInstance() {
    if (instance == NULL)
        instance = new Game();
    return instance;
}

const int Game::getRoundNumber() const {
    return round_number;
}

const Player Game::getPlayer(const unsigned int playerID) const {
    return players.at(playerID);
}

const bool Game::isGameDone() const {
    return round_number >= total_rounds;
}

const Player& Game::getCurrentWinner const {
    int winnerID = player_IDs[0];
    for (const unsigned int id : player_IDs) {
        if getPlayer(winnerID) < getPlayer(id)
            winnerID = id;
    }
    return getPlayer(winnerID);
}

const unsigned int Game::addPlayer(const std::map<unsigned int, unsigned int>& answerIDs) {
    player_number++;
    player_IDs.push_back(player_number);
    players[player_number] = Player(answerIDs, 0, player_number);
    return player_number;
}

void Game::startNextRound() {
    if (round_number < total_rounds) {
        current_round = Round(player_IDs, round_length, point_value, time_bonus);
        round_number++;
        for (const auto& player : players) {
            player.second.setRound(&current_round);
        }
    }
    TimeManager::getInstance().getTimer(between_rounds_timer).stopTimer();
}

void Game::restart(const int roundNo = 0) {
    round_number = roundNo;
    startNextRound();
}

const Round* Game::getCurrentRound() const {
    return &current_round;
}

void Game::setGameLength(const unsigned int rounds) {
    total_rounds = rounds;
}

void Game::setRoundTime(const double round_length) {
    this->round_length = round_length;
}

void Game::setPointValue(const unsigned int point_value) {
    this->point_value = point_value;
}

void Game::setTimeBonus(const unsigned int time_bonus) {
    this->time_bonus = time_bonus;
}

void Game::update() {
    //InputManager::getInstance().updateAll();
    TimeManager::getInstance().update();

    if (TimeManager::getInstance().getTimer(between_rounds_timer).isTimerDone())
        startNextRound();
    bool ready = true;
    for (const unsigned int id : player_IDs) {
        if (!getPlayer(id).isAnswerReady())
            ready = false;
    }
    if (ready = true || getCurrentRound().isTimeUp()) {
        for (const auto& scoreWon : getCurrentRound().evaluateScores()) {
            getPlayer(scoreWon.first).addScore(scoreWon.second);
        }
        TimeManager::getInstance().getTimer(between_rounds_timer).restartTimer();
    }
}
