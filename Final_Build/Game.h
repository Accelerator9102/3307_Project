/// @class Game
/// @author Daniel Carranza
/// @brief Class containing the general game loop.
/// This class is responsible for running the trivia game and connecting all the pieces together.

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <algorithm>
#include "Player.h"
#include "Round.h"
#include "InputManager.h"

class Game
{
    public:
        /// @brief Destructor method.
        virtual ~Game();
        
        /// @brief Method to retrieve an instance of Game.
        /// @return A static reference to the Game instance.
        static Game& getInstance();

        /// @brief Method to retrieve the current round number.
        /// @return The current round number.
        const int getRoundNumber() const;
        
        /// @brief Method to retrieve a player given its ID.
        /// @param playerID The ID of the player to be found.
        /// @return A reference to the player object the ID represents.
        const Player& getPlayer(const unsigned int playerID) const;
        
        /// @brief Method to determine if the game has concluded.
        /// @return Whether or not the game is over.
        const bool isGameDone() const;
        
        /// @brief Method to determine the current leading player.
        /// @return A reference to the winning player.
        const Player& getCurrentWinner() const;
        
        /// @brief Method to add a new player to the game.
        /// @param answerIDs A map containing the I/O pins for each input and their corresponding answer buttons.
        /// @return The ID of the new player.
        const unsigned int addPlayer(const std::map<unsigned int, unsigned int>& answerIDs);
        
        /// @brief Method to begin a new round.
        void startNextRound();
        
        /// @brief Method to determine if a round is currently ongoing.
        /// @return Whether or not the round is ongoing.
        const bool isRoundLive() const;
        
        /// @brief Method to restart the game from a specified point.
        /// @param roundNo The round to reset the game to. Defaults to 0.
        void restart(const int roundNo = 0);
        
        /// @brief Method to retrieve the current round.
        /// @return A pointer to the current Round object.
        const Round* getCurrentRound() const;
        
        /// @brief Method to set game length.
        /// @param rounds The number of rounds.
        void setGameLength(const unsigned int rounds);
        
        /// @brief Method to set the timelength of each round.
        /// @param round_length How long the rounds should be.
        void setRoundTime(const double round_length);
        
        /// @brief Method to set the points gained per correct answer.
        /// @param point_value The amount of points gained on a correct answer.
        void setPointValue(const unsigned int point_value);
        
        /// @brief Method to set the bonus for answering quickly.
        /// @param time_bonus The multiplier used to increase score based on answer speed.
        void setTimeBonus(const unsigned int time_bonus);
        
        /// @brief Game loop.
        void update();

    private:
        /// @brief Default constructor.
        Game();
        
        // Prevent copying and assignment
        Game(const Game& other) { };
        const Game& operator=(const Game& other) { };
        
        static Game* instance; /// @brief An instance of QuestionManager.

        unsigned int total_rounds; /// @brief The total numebr of rounds.
        double round_length; /// @brief The time per round.
        unsigned int point_value; /// @brief Number of points for correct answers.
        unsigned int time_bonus; /// @brief The multiplier for answering quickly.
        unsigned int round_number; /// @brief The current round number.
        double time_between_rounds; /// @brief The time between different rounds.
        unsigned int between_rounds_timer; /// @brief The ID of the timer for between rounds.
        int player_number; /// @brief Number of players.
        Round current_round; /// @brief The current round.
        std::map<unsigned int, Player> players; /// @brief A map of players and their IDs.
        std::vector<unsigned int> player_IDs; /// @brief A vector of playerIDs.
};

#endif // GAME_H
