/// @class InputManager
/// @author Alexandra Drazilov
/// @brief This is the header file for the InputManager class.
/// This file is the frame work for the manager of many Input instances

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_
#include "Input.h"
#include "Player.h"

class InputManager{ 
	
	public:
		/// @brief Destructor method.
		~InputManager();
	
		/// @brief Method to retrieve an instance of InputManager.
		/// @return A static reference to the InputManager instance.
		static InputManager& getInstance();
		
		/// @brief Method to process input for all input devices.
		void updateAll();
		
		/// @brief Method to create a new player input configuration.
		/// @param pins The I/O pins used for the player.
		/// @param player the player object to be associated with the specified input devices.
		void addPlayer(std::vector<int> pins, const Player* player);
		
	private:
		/// @brief Constructor method.
		InputManager();
		
		std::vector<std::vector<Input> > inputs; /// @brief A 2D vector containing all input devices.
		static InputManager* instance /// @brief An instance of InputManager.
};

#endif

