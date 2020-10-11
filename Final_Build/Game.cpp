#include "Game.h"

Game* Game::instance = NULL;

/// This constructor method initializes values.
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

/// Destructor.
Game::~Game() { }

/// This method returns an instance of the TimeManager object.
/// If an instance doesn't already exist, it creates one.
Game& Game::getInstance() {
    if (instance == NULL)
        instance = new Game();
    return *instance;
}

/// This method retrieves the current round number.
const int Game::getRoundNumber() const {
    return round_number;
}

/// This method retrieves a player based on the given ID.
const Player& Game::getPlayer(const unsigned int playerID) const {
    return players.at(playerID);
}

/// This method determines if the game is done by checking if the round number has exceeded the maximum.
const bool Game::isGameDone() const {
    return round_number >= total_rounds;
}

/// Retrieves the player that is currently in the lead.
const Player& Game::getCurrentWinner() const {
    int winnerID = player_IDs[0];
    for (const unsigned int id : player_IDs) {
        if (getPlayer(winnerID) < getPlayer(id))
            winnerID = id;
    }
    return getPlayer(winnerID);
}

/// This method adds a new player to the game.
const unsigned int Game::addPlayer(const std::map<unsigned int, unsigned int>& answerIDs) {
    player_number++;
    player_IDs.push_back(player_number);
    players[player_number] = Player(answerIDs, 0, player_number);
    return player_number;
}

/// This method starts a new round.
void Game::startNextRound() {
    if (round_number < total_rounds) {
        current_round = Round(round_length, point_value, time_bonus);
        round_number++;
        for (auto& player : players) {
            player.second.setRound(&current_round);
        }
    }
    TimeManager::getInstance().getTimer(between_rounds_timer).restartTimer();
    TimeManager::getInstance().getTimer(between_rounds_timer).stopTimer();
}

/// This method determines if a round is currently ongoing.
const bool Game::isRoundLive() const {
    return (TimeManager::getInstance().getTimer(between_rounds_timer).getCurrentTime() == 0);
}

/// This method restarts the game to the set round number, allowing it to continue for longer.
void Game::restart(const int roundNo) {
    round_number = roundNo;
    startNextRound();
}

/// This method retrieves a pointer to the current round object.
const Round* Game::getCurrentRound() const {
    return &current_round;
}

/// This method sets the game length.
void Game::setGameLength(const unsigned int rounds) {
    total_rounds = rounds;
}

/// This method sets the round length.
void Game::setRoundTime(const double round_length) {
    this->round_length = round_length;
}

/// This method sets the point value for correct answers.
void Game::setPointValue(const unsigned int point_value) {
    this->point_value = point_value;
}

/// This method sets the bonus for answering quickly.
void Game::setTimeBonus(const unsigned int time_bonus) {
    this->time_bonus = time_bonus;
}

/// This method contains the general game loop that handles everything.
void Game::update() {
    InputManager::getInstance().updateAll();
    TimeManager::getInstance().update();

    //std::cout << "Time between rounds: " << TimeManager::getInstance().getTimer(between_rounds_timer).getCurrentTime()
    //    << "/" << TimeManager::getInstance().getTimer(between_rounds_timer).getStopTime() << std::endl;
    if (TimeManager::getInstance().getTimer(between_rounds_timer).isTimerDone()) {
        //std::cout << "last christmas" << std::endl;
        startNextRound();
    }
    bool ready = true;
    for (auto it = player_IDs.begin(); it != player_IDs.end(); it++) {
        if (!getPlayer(*it).isAnswerReady()) {
            ready = false;
            //std::cout << *it << "/" << player_IDs.size() - 1 << " Falso" << std::endl;
        }
    }
    if (ready || getCurrentRound()->isTimeUp()) {
        auto newScores = getCurrentRound()->evaluateScores();
        for (auto it = newScores.begin(); 
                it != newScores.end();
                it++) {
            //std::cout << "Player " << it->first << ", that is " 
            //    << ( (it->second > 0)? "correct!" : "incorrect!" ) << it->second << std::endl;
            getPlayer(it->first).addScore(it->second);
        }
        TimeManager::getInstance().getTimer(between_rounds_timer).startTimer();
    }
}
