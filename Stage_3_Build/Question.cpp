#include "Question.h"

using namespace std;

/// This constructor generates all of the data for a single question
/// by using an API helper. It then computes a random offset and 
/// inserts the correct answer and the incorrect answers into the
/// options vector. Lastly, it stores the index of the correct answer.
Question::Question(string token) {
	Json::Value questionData;
	questionData = APIHelper::getInstance().getQuestion(token);
	
	if (questionData == -1)
		throw -1;
	
	question = questionData["results"][0]["question"].asString();
	
	srand(time(NULL));
	int answerOffset = rand() % 4;
	
	options = vector<string>(4);
	options[(0 + answerOffset) % 4] = questionData["results"][0]["correct_answer"].asString();
	options[(1 + answerOffset) % 4] = questionData["results"][0]["incorrect_answers"][0].asString();
	options[(2 + answerOffset) % 4] = questionData["results"][0]["incorrect_answers"][1].asString();
	options[(3 + answerOffset) % 4] = questionData["results"][0]["incorrect_answers"][2].asString();
	correctAnswer = (0 + answerOffset) % 4;
}

/// Destructor.
Question::~Question() {		
}

/// This simply returns the string storing the question obtained from initialization.
string Question::getQuestion() {
	return question;
}

/// This simply returns the vector storing the answers obtained from initialization.
vector<string> Question::getOptions() {
	return options;
}

/// This simply returns the int storing the index of the correct answer obtained from initialization.
int Question::getAnswer() {
	return correctAnswer;
}
