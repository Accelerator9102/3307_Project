/// @class Player
/// @author Daniel Carranza
/// @brief Class to handle the Player.
/// This class stores all necessary values for a given player and processes
/// their input.

#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <iostream>
#include "Round.h"

class Player
{
    public:
        /// @brief Constructor method.
        /// @param answerIDs A map containing the port numbers and their answer indices. Defaults to blank.
        /// @param round The current round of the game. Defaults to 0.
        /// @param playerID The ID of the player. Defaults to 0.
        Player(const std::map<unsigned int, unsigned int>& answerIDs = {},
               const Round* round = 0,
               const unsigned int& playerID = 0);
               
        /// @brief Destructor method.
        ~Player();

        /// @brief Method to retrieve the player's ID.
        /// @return An unsigned int referring to the player's ID.
        const unsigned int getPlayerID() const;
        
        /// @brief Method to retrieve the player's current score.
        /// @return An int containing the score.
        const int getScore() const;
        
        /// @brief Method to retrieve the player's selected answer.
        /// @return An int referring to the player's selected answer.
        const int getAnswer() const;
        
        /// @brief Method to increase the player's score by a set amount.
        /// @param amount The amount of points to be added. Defaults to 0.
        void addScore(const unsigned int amount = 0) const;
        
        /// @brief Method to reset the player's score to 0.
        void resetScore();
        
        /// @brief Method to determine if the player has selected their answer.
        /// @return Whether or not the player has selected their answer.
        const bool isAnswerReady() const;
        
        /// @brief Method to set the current round.
        /// @param round The round to set the player's inputs for.
        void setRound(const Round* round);
        
        /// @brief Method to receive and store inputs.
        /// @param inputID The ID of the input that sent the signal.
        void notify(const unsigned int& inputID) const;
        
        // Used for comparing score
        const bool operator<(const Player& other) const;

    private:
        unsigned int id; /// @brief Player ID.
        mutable bool is_answering; /// @brief Whether or not the player should receive input.
        std::map<unsigned int, unsigned int> answerIDs; /// @brief Map storing the I/O ports and their corresponding answer indices.
        mutable int score; /// @brief The player's score.
        mutable int currentAnswer; /// @brief The player's current selected answer.
        const Round* round; /// @brief The current round the player is on.
};

#endif // PLAYER_H
