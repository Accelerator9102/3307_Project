#include "Round.h"

/// Constructs a Round oject with specified time and point data
Round::Round(const double round_length,
             const unsigned int point_value,
             const unsigned int time_bonus) {
    this->round_length = round_length;
    this->point_value = point_value;
    this->time_bonus = time_bonus;
    question = QuestionManager::getInstance().getQuestion();
    timer = TimeManager::getInstance().addTimer(round_length, true);
    TimeManager::getInstance().getTimer(timer).startTimer();
}

/// Desctructs a Round object
Round::~Round() {
    TimeManager::getInstance().removeTimer(timer);
}

/// Returns the question of this round
const std::string Round::getQuestion() const {
    return question.getQuestion();
}

/// Returns the vector of answers for this round
const std::vector<std::string> Round::getAnswers() const {
    return question.getOptions();
}

/// Returns the correct answer of this round
const std::string Round::getCorrectAnswer() const {
    return question.getOptions()[question.getAnswer()];
}

/// Returns the index of the correct answer this round
const unsigned int Round::getCorrectAnswerIndex() const {
    return question.getAnswer();
}

/// Returns the time remaining this round
const double Round::getCurrentRoundTime() const {
    TimeManager::getInstance().getTimer(timer).startTimer();
    return round_length - TimeManager::getInstance().getTimer(timer).getCurrentTime();
}

/// Returns true if the time for this round has passed
const bool Round::isTimeUp() const {
    return Round::getCurrentRoundTime() <= 0;
}

/// Adds an answer to the list of submitted answers
void Round::submitAnswer(unsigned int playerID, unsigned int answer) const {
    submitted_answers[playerID] = {answer, getCurrentRoundTime()};
}

/// Evaluates the points earned for answers submitted this round
const std::map<unsigned int, unsigned int> Round::evaluateScores() const {
    std::map<unsigned int, unsigned int> scores;
    for (auto it = submitted_answers.begin(); it != submitted_answers.end(); it++) {
        scores[it->first] = ( (it->second.first == question.getAnswer())? 
            point_value + time_bonus*it->second.second : 0 );
    }
    return scores;
}
