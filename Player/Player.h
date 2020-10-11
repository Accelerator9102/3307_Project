#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include "Round.h"

class Player
{
    public:
        Player(const std::map<int, int>& answerIDs,
               const Round* round,
               const unsigned int& playerID);
        ~Player();

        const unsigned int getPlayerID() const;
        const int getScore() const;
        const int getAnswer() const;
        void addScore(const unsigned int& amount);
        void resetScore();
        const bool isAnswerReady() const;
        void setRound(const Round* round);
        void notify(const int& inputID);
        const bool operator<(const Player& other) const;

    private:
        unsigned int id;
        std::map<int, int> answerIDs;
        int score;
        int currentAnswer;
        const Round* round;
};

#endif // PLAYER_H
