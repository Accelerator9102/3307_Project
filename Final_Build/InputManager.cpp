#include "InputManager.h"

//std::vector<std::vector<Input*> > inputs;
InputManager* InputManager::instance = NULL;

/// Constructor.
InputManager::InputManager() { }

/// Destructor.
InputManager::~InputManager(){}

/// This method runs through every input object and updates a player's answer
/// if one of the I/O devices is receiving input.
void InputManager::updateAll(){
	for(auto i = inputs.begin(); i != inputs.end(); i++){
		for(auto j = i->begin(); j != i->end(); j++){
			j->updatePlayer();
		}
	}
}

/// This method returns an instance of the InputManager object.
/// If an instance doesn't already exist, it creates one.
InputManager& InputManager::getInstance(){
	if(instance == NULL){
		instance = new InputManager();
	}
	return *instance;
}

/// This method pairs a new player to specified I/O devices and stores this configuration.
void InputManager::addPlayer(std::vector<int> pins, const Player* player){
	//int pins[2][4] = {{-1,0,2,3},{6,5,4,1}};  //These pins correlate to the pins set on the board.
	int i = 0;
	std::vector<Input> saved_player;
	for(auto j = pins.begin(); j != pins.end(); j++){
		saved_player.push_back(Input(*j, i, player)); //Each pin is turned into an input and stored
	}
	inputs.push_back(saved_player);
}
