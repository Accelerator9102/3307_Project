/// @class Question
/// @author Mhd Taisir Sahlol
/// @brief Stores all needed attributes relating to a single question.
/// This class is intended to store the necessary attributes for a
/// question, such as the question itself, the possible options, and
/// the index of the correct answer.

#ifndef QUESTION_H
#define QUESTION_H

#include "iostream"
#include "vector"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "APIHelper.h"

class Question {
	
	public:
		/// @brief Constructor method.
		/// @param token The token used for API calls to ensure no duplicates are received. Defaults to blank.
	    Question(std::string token = "");
	    
	    /// @brief Destructor method.
		~Question();
		
		/// @brief Method used to obtain the question string.
		/// @return A string containing the question obtained during construction.
		const std::string getQuestion() const;
		
		/// @brief Method used to obtain the possible answers to the question.
		/// @return A vector containing strings of all the possible answers.
		const std::vector<std::string> getOptions() const;
		
		/// @brief Method used to obtain the correct answer to the question.
		/// @return An integer representing the index of the correct answer from the options vector.
		const int getAnswer() const;
	private:
		std::string question; /// @brief String to contain the actual question.
		std::vector<std::string> options; /// @brief Vector containing all possible options.
		int correctAnswer; /// @brief Int containing the index in options of the correct answer.
};

#endif
