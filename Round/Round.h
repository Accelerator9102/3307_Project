#ifndef ROUND_H
#define ROUND_H

#include "QuestionManager.h"
#include "TimeManager.h"
#include <vector>
#include <map>
#include <pair>

class Round
{
    public:
        Round(const std::vector<unsigned int>& playerIDs,
              const double round_length,
              const unsigned int point_value,
              const unsigned int time_bonus);
        ~Round();

        const std::string getQuestion() const;
        const std::vector<std::string> getAnswers() const;
        const double getCurrentRoundTime() const;
        const bool isTimeUp() const;
        void submitAnswer(unsigned int playerID, unsigned int answer);
        const std::map<unsigned int, unsigned int> evaluateScores() const;
    private:
        const double ROUND_LENGTH;
        const unsigned int POINT_VALUE;
        const unsigned int TIME_BONUS;
        Question question;
        int timer;
        std::map<unsigned int, std::pair<unsigned int, double>> submitted_answers;

};

#endif // ROUND_H
