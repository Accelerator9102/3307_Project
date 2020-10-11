/// @class QuestionManager
/// @author Mhd Taisir Sahlol
/// @brief Retrieves questions and keeps track of questions already asked.
/// This class is meant to be the interface by which other classes can
/// retrieve objects of type Question. It also keeps track of a token which
/// can be used to determine which questions have already been provided.

#ifndef QUESTIONMANAGER_H
#define QUESTIONMANAGER_H

#include "iostream"
#include "stdio.h"
#include "vector"
#include "string.h"
#include "APIHelper.h"
#include "Question.h"

class QuestionManager {
	
	public:  
	    /// @brief Destructor method.
		~QuestionManager();
		
		/// @brief Method to retrieve an instance of QuestionManager.
		/// @return A static reference to the QuestionManager instance.
		static QuestionManager& getInstance();
		
		/// @brief Method to retrieve a single question.
		/// @return An object of type Question containing all relevant information.
		const Question getQuestion() const;
		
		// Not used in prototype
		/// @brief Method to reset the API token.
		void resetQuestions();

	private:
		/// @brief Constructor method.
	    QuestionManager();
	    
	    // Prevent copying and assignment
	    QuestionManager(const QuestionManager& other) { };
	    QuestionManager& operator=(const QuestionManager& other) { };
	    
		static QuestionManager* instance; /// @brief An instance of QuestionManager.
		
		std::string token; /// @brief Token to keep track of which questions have been asked.
};

#endif
