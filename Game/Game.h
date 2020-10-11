#ifndef GAME_H
#define GAME_H

#include <vector>
#include <algorithm>
#include "Player.h"
#include "Round.h"

class Game
{
    public:
        virtual ~Game();
        static Game& getInstance();

        const int getRoundNumber() const;
        const Player getPlayer(const unsigned int playerID) const;
        const bool isGameDone() const;
        const Player& getCurrentWinner() const;
        const unsigned int addPlayer(const std::map<unsigned int, unsigned int>& answerIDs);
        void startNextRound();
        void restart(const int roundNo);
        const Round* getCurrentRound() const;
        void setGameLength(const unsigned int rounds);
        void setRoundTime(const double round_length);
        void setPointValue(const unsigned int point_value);
        void setTimeBonus(const unsigned int time_bonus);
        void update();

    private:
        Game();
        Game(const Game& other) { };
        const Game& operator=(const Game& other) { };
        static Game* instance;

        unsigned int total_rounds;
        double round_length;
        unsigned int point_value;
        unsigned int time_bonus;
        unsigned int round_number;
        unsigned int between_rounds_timer;
        double time_between_rounds;
        int player_number;
        Round current_round;
        std::map<unsigned int, Player> players;
        std::vector<unsigned int> player_IDs;
};

#endif // GAME_H
