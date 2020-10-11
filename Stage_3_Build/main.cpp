#include "APIHelper.h"
#include "Question.h"
#include "QuestionManager.h"

using namespace std;

// Main function used for the prototype trivia game.
int main(void)
{
	// Try to run through the game. Handle exceptions that pop up.
	try {
		// Initialize QuestionManager to retrieve questions,
		// a string buffer to store user answers, and an integer representing score.
	
		string selection;
		int score = 0;
	
		// Game runs for 10 rounds.
		for (int i = 1; i <= 10; i++) {
			cout << "ROUND " << i << " / 10" << endl << endl;
			// Get question and then display the question along with 4 possible choices.
			Question q = QuestionManager::getInstance().getQuestion();
			cout << q.getQuestion() << endl;
			cout << "1) " << q.getOptions()[0] << endl;
			cout << "2) " << q.getOptions()[1] << endl;
			cout << "3) " << q.getOptions()[2] << endl;
			cout << "4) " << q.getOptions()[3] << endl << endl;
		
			// Processing user input.
			cout << "Enter '1', '2', '3', '4' to select your answer:" << endl;
			cin >> selection;
			cout << endl;
		
			// If correct, increment score. Otherwise, don't.
			if (selection == to_string(q.getAnswer() + 1)) {
				cout << "Correct!" << endl << endl;
				score++;
			}
			else
				cout << "Incorrect! The correct answer was: " << q.getAnswer() + 1 << endl << endl;		
		} 
		
		// Print out final score.
		cout << "The game is over! Your final score is: " << score << " / 10" << endl;
	}
	
	// If question fails to be retrieved.
	catch (int e) {
		if (e == -1)
			cout << "Question could not be retrieved, exiting program" << endl;
		if (e == -2)
			cout << "QuestionManager could not be initialized, exiting program" << endl;
		return -1;
	}
	
	return 1;
}
