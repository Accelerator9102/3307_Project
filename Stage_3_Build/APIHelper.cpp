#include "APIHelper.h"

using namespace std;

APIHelper* APIHelper::instance = NULL;

/// Constructor.
APIHelper::APIHelper() {
}

/// Destructor.
APIHelper::~APIHelper() {		
}

/// This method returns an instance of the APIHelper object.
/// If an instance doesn't already exist, it creates one.
APIHelper& APIHelper::getInstance() {
    if (instance == NULL) {
        instance = new APIHelper();
    }
    return *instance;
}

/// This method sets the url for the API call to be the link to OpenTDB's
/// question retrieval service with the token appended to it. If successful,
/// it will return the Json object containing all information about the
/// question. Otherwise, it returns -1 to indicate something went wrong.
Json::Value APIHelper::getQuestion(string token) {
	string url = "https://opentdb.com/api.php?amount=1&type=multiple&token=" + token;
	Json::Value questionData = apiCall(url);
	if (questionData == -1)
		return -1;
	if (questionData["response_code"] == 0)
		return questionData;
		
	return -1;
}

/// This method sets the url for the API call to be the link to OpenTDB's
/// token retrieval service with the token appended to it. If successful,
/// it will return the string containing the token. Otherwise, it will return
/// an empty string to indicate something went wrong.
string APIHelper::getToken() {
	string url = "https://opentdb.com/api_token.php?command=request";
	Json::Value tokenData = apiCall(url);
	if (tokenData == -1)
		return NULL;
	if (tokenData["response_code"] == 0)
		return tokenData["token"].asString();
	
	return "";
}

// Not used for prototype
/// This method sets the url for the API call to be the link to OpenTDB's
/// token resetting service with the token appended to it. It will return
/// whatever response code the API generates. 0 indicates a success, and
/// anything else indicates a failure.
int APIHelper::resetToken(string token) {
	string url = "https://opentdb.com/api_token.php?command=reset&token=" + token;
	Json::Value tokenData = apiCall(url);
		
	return tokenData["response_code"].asInt();
}

/// This is the standard callback method provided from example code in
/// the documentation for CURL. It copies the contents from a url into
/// a string buffer, and then returns the real size of the url's contents.
size_t APIHelper::callback(void *contents, size_t size, size_t nmemb, void *userp) {
	size_t realsize = size * nmemb;
	((string *) userp)->append((char *) contents, realsize);
	return realsize;
}

// This code is partially sourced from the examples provided in libcurl's
// documentation. It is altered to perform the requests that we need.
/// This is the function to make a call to the API. It does so by using
/// CURL. If successful, it will return the Json object generated by parsing
/// through the URL. If it can't create a Json value, it returns -1.
/// If CURL failed for whatever reason, the program will automatically exit
/// and display the reasoning.
Json::Value APIHelper::apiCall(string url) {	
	CURL *curl;
	CURLcode res;
	string buffer;
	
	curl = curl_easy_init();
	
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
 
		/* Perform the request, res will get the return code */ 
		res = curl_easy_perform(curl);
		
		/* Check for errors */ 
		if(res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
		curl_easy_cleanup(curl);
		
		Json::Value jsonData;
		Json::Reader jsonReader;
		
		if (jsonReader.parse(buffer, jsonData)) {
			return jsonData;
		}
	}
	
	return -1;
}
