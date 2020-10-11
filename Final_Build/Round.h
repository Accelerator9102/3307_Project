/// @class Round
/// @author Daniel Carranza
/// @brief Contains all behaviour specific to each round of trivia
/// This class stores the round timer and evaluates scores

#ifndef ROUND_H
#define ROUND_H

#include "QuestionManager.h"
#include "TimeManager.h"
#include <vector>
#include <map>
#include <utility>

class Round
{
    public:
        /// @brief Constructor method
        /// @param round_length Duration (in seconds) of this round
        /// @param point_value How many points a correct answer is worth
        /// @param time_bonus Up to how many bonus points are awarded for answering earlier
        Round(const double round_length = 30,
              const unsigned int point_value = 100,
              const unsigned int time_bonus = 100);
        
        /// @brief Destructor method
        ~Round();

        /// @brief Returns the question of this round as a string
        /// @return Round question as a string
        const std::string getQuestion() const;
        
        /// @brief Returns the list of possible answers this round as a vector of strings
        /// @return Vector of answers as a string
        const std::vector<std::string> getAnswers() const;
        
        /// @brief Returns the correct answers of this roud as a string
        /// @return String of correct answer
        const std::string getCorrectAnswer() const;
        
        /// @brief Returns the index of the correct answer to this round
        /// @return Index of correct answer
        const unsigned int getCorrectAnswerIndex() const;
        
        /// @brief Returns how much time (in seconds) is remaining this round
        /// @return Time left this round
        const double getCurrentRoundTime() const;
        
        /// @brief Returns true if the round has exceeded the time limit
        /// @return True if the time is passed this round, false otherwise
        const bool isTimeUp() const;
        
        /// @brief Adds an answer for evaluation at the end of the round
        /// @param playerID ID of the player submitting this answer
        /// @param answer Index of the answer submitted
        void submitAnswer(unsigned int playerID, unsigned int answer) const;
        
        /// @brief Evaluates the scoring of submitted answers
        /// @return Map of scores where the key is the player IDs, and the values are their respective points earned this round
        const std::map<unsigned int, unsigned int> evaluateScores() const;
        //void operator=(const Round& other);
    private:
        double round_length; /// @brief Duration of the round in seconds
        unsigned int point_value; /// @brief Points awarded for guessing correctly this round
        unsigned int time_bonus; /// @brief Bonus points for answering early this round
        Question question; /// @brief Question data for this round
        int timer; /// @brief ID of Timer used to track the time of this round
        mutable std::map< unsigned int, std::pair<unsigned int, double> > submitted_answers; /// @brief Map of submitted answers, where keys are player IDs, and values are pairs of submitted answer indices, along with the time the answer was submitted

};

#endif // ROUND_H
