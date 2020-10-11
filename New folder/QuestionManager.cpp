#include "QuestionManager.h"

using namespace std;

QuestionManager* QuestionManager::instance = NULL;

/// This method constructs a QuestionManager object.
/// To do so, the token needs to be initialized so an APIHelper object
/// must be created first.
QuestionManager::QuestionManager() {
	token = APIHelper::getInstance().getToken();
	if (token == "")
		throw -2;
}

/// Destructor.
QuestionManager::~QuestionManager() {		
}

/// This method returns an instance of the QuestionManager object.
/// If an instance doesn't already exist, it creates one.
QuestionManager& QuestionManager::getInstance() {
    if (instance == NULL) {
        instance = new QuestionManager();
    }
    return *instance;
}

/// This method attempts retrieves an object of type Question by
/// passing the token along to prevent duplicates. If this is successful
/// the Question object is returned and otherwise we throw an exception.
const Question QuestionManager::getQuestion() const {
	try {
		Question q(token);
		return q;
	} catch (int e) {
		throw -1;
	}
}

/// This method resets the token on the API so that previously received
/// questions can be obtained again.
void QuestionManager::resetQuestions() {
	APIHelper::getInstance().resetToken(token);
}
