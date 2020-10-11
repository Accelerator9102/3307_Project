/// @class APIHelper
/// @author Mhd Taisir Sahlol
/// @brief Helper class used to make API Calls whenever they are needed.
/// This class serves to perform all communication between the program
/// and the OpenTDB API. It has functions allowing it to retrieve
/// questions, tokens, and reset tokens.

#ifndef APIHELPER_H
#define APIHELPER_H

#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "curl/curl.h"
#include "jsoncpp/json/json.h"

class APIHelper {
	
	public:
		/// @brief Destructor method.
		~APIHelper();
		
		/// @brief Method to retrieve an instance of APIHelper.
		/// @return A static reference to the APIHelper instance.
		static APIHelper& getInstance();
		
		/// @brief Method to retrieve a question from the API.
		/// @param token The token used to ensure duplicate questions are not received.
		/// @return A random question from the API in Json format.
		Json::Value getQuestion(std::string token);
		
		/// @brief Method to retrieve a token from the API.
		/// @return A string representing the generated token from the API.
		std::string getToken();
		
		// Not used for prototype
		/// @brief Method to reset a token so that seen questions may be received again.
		/// @param token The token to be reset.
		/// @return The code from the API representing success or failure.
		int resetToken(std::string token);
		
	private:
		/// @brief Constructor method.
	    APIHelper();
	    
	    // Prevent copying and assignment
	    APIHelper(const APIHelper& other) { };
	    APIHelper& operator=(const APIHelper& other) { };
	    
	    static APIHelper* instance; /// @brief An instance of APIHelper.
		
		// This is the standard callback method used in all sample code I could find for CURL.
		/// @brief Method used to put the results from CURL into a string buffer.
		/// @param contents A pointer to the contents of the URL.
		/// @param size Size.
		/// @param nmemb Number of members.
		/// @param userp A pointer to the string buffer to store data into.
		/// @return The real size of the file.
		static size_t callback(void *contents, size_t size, size_t nmemb, void *userp);
		
		/// @brief Method used to directly make calls to the API.
		/// @param url The URL to pass into CURL for retrieval.
		/// @return The Json object retrieved from parsing through the buffer string or -1 if it failed.
		Json::Value apiCall(std::string url);
};

#endif
