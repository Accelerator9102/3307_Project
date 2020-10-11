/*
 * Trivia Game main program
 */
#include "Game.h"
#include <iostream>

int main(int argc, char *argv[]){

	const int SPECIAL_NUMBERS[7] = {30, 20, 10, 5, 3, 2, 1};
	int next_special_number = 0;
	
	unsigned int p1 =
		Game::getInstance().addPlayer( {{0, 0}, {2, 1}, {3, 2}} );
	unsigned int p1_last_score = 0;
	unsigned int p2 = 
		Game::getInstance().addPlayer( {{4, 0}, {5, 1}, {6, 2}} );
	unsigned int p2_last_score = 0;
	
	InputManager::getInstance().addPlayer({0, 2, 3}, &Game::getInstance().getPlayer(p1));
	InputManager::getInstance().addPlayer({4, 5, 6}, &Game::getInstance().getPlayer(p2));
	
	Game::getInstance().startNextRound();
	int lastFrameRound = 0;
	double lastTime = 100;
	bool is_score_shown = false;
	while (!Game::getInstance().isGameDone()) {
		Game::getInstance().update();
		
		if (lastFrameRound != Game::getInstance().getRoundNumber()) {
			std::cout << "The score is: " << std::endl;
			std::cout << "Player 1: " << Game::getInstance().getPlayer(p1).getScore() << std::endl;
			std::cout << "Player 2: " << Game::getInstance().getPlayer(p2).getScore() << std::endl;
						
			std::cout << Game::getInstance().getCurrentRound()->getQuestion() << std::endl;
			for (unsigned int i = 0; i < Game::getInstance().getCurrentRound()->getAnswers().size(); i++) {
				std::cout << i << ") " << Game::getInstance().getCurrentRound()->getAnswers()[i] << std::endl;
			}
			is_score_shown = false;
			lastTime = 105;
			next_special_number = 0;
		}
		
		double time = Game::getInstance().getCurrentRound()->getCurrentRoundTime();
		//std::cout << time << " - " << lastTime << std::endl;
		if (time < lastTime) {
			if (next_special_number < 7 && time < SPECIAL_NUMBERS[next_special_number]) {
				std::cout << SPECIAL_NUMBERS[next_special_number];
				next_special_number++;
			}
			else
				std::cout << ".";
			std::cout.flush();
			lastTime = time;
		}
		
		unsigned int p1_score = Game::getInstance().getPlayer(p1).getScore();
		unsigned int p2_score = Game::getInstance().getPlayer(p2).getScore();
		
		if ((!is_score_shown) && 
			(Game::getInstance().getCurrentRound()->isTimeUp() 
				|| p1_score != p1_last_score
				|| p2_score != p2_last_score )) {
			std::cout << "Round over." << std::endl;
			std::cout << "The correct answer is: " 
				<< Game::getInstance().getCurrentRound()->getCorrectAnswerIndex() << ") "
				<< Game::getInstance().getCurrentRound()->getCorrectAnswer()
				<< std::endl;
			std::cout << std::endl
				<< "Player 1 wins " 
				<< Game::getInstance().getPlayer(p1).getScore() - p1_last_score
				<< " points." << std::endl
				<< "Player 2 wins "
				<< Game::getInstance().getPlayer(p2).getScore() - p2_last_score
				<< " points. " << std::endl;
			lastTime = 0;
			is_score_shown = true;
		}
		
		lastFrameRound = Game::getInstance().getRoundNumber();
		p1_last_score = Game::getInstance().getPlayer(p1).getScore();
		p2_last_score = Game::getInstance().getPlayer(p2).getScore();
	}
	
}
