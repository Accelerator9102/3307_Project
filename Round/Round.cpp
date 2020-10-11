#include "Round.h"

Round::Round(const std::vector<unsigned int>& playerIDs,
             const double round_length = 30,
             const unsigned int point_value = 100,
             const unsigned int time_bonus = 100) :
                 ROUND_LENGTH(round_length), POINT_VALUE(point_value), TIME_BONUS(time_bonus) {
    question = QuestionManager::getInstance().getQuestion();
    timer = TimeManager::getInstance().addTimer(ROUND_LENGTH);
    submitted_answers = playerIDs;
}

Round::~Round() {
    TimeManager::getInstance().removeTimer(timer);
}

const std::string Round::getQuestion() const {
    return question.getQuestion();
}

const std::vector<std::string> Round::getAnswers() const {
    return question.getOptions();
}

const double Round::getCurrentRoundTime() const {
    return ROUND_LENGTH - TimeManager::getInstance().getTimer(timer).getCurrentTime();
}

const double Round::isTimeUp() const {
    return Round::getCurrentRoundTime() <= 0;
}

void Round::submitAnswer(unsigned int playerID, unsigned int answer) {
    submitted_answers[playerID] = std::pair<unsigned int, double>(answer, getCurrentRoundTime());
}

const std::map<unsigned int, unsigned int> Round::evaluateScores() const {
    std::map<unsigned int, unsigned int> scores;
    for (const auto& it : submitted_answers) {
        scores[it.first] = (it.second.first == question.getAnswer())? 100 + 100*it.second.second : 0;
    }
    return scores;
}

