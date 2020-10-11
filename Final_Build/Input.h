/// @class Input
/// @author Alexandra Drazilov
/// @brief Input creates and manipulates the hardware for user input.
/// This class stores all necessary values for any given Input object and
/// also contains ways to notify the associated player(s) if input is received.
#ifndef INPUT_H_
#define INPUT_H_
#include <iostream>
#include <wiringPi.h>
#include "Player.h"

class Input{
		
	public:
		/// @brief Default constructor method.
		Input();
		
		/// @brief Constructor method.
		/// @param ID The ID of the input object.
		/// @param buttonNumber The number corresponding to a single button's answer.
		/// @param player A pointer to the player object associated with the input object.
		Input(int ID, int buttonNumber, const Player* player);
		
		/// @brief Destructor method.
		~Input();
		
		/// @brief Method to tell the player object if input has been received.
		void updatePlayer();
		
		/// @brief Method to determine if the input object is on or not.
		/// @return Whether or not the input object is on.
		bool getState();
		
		/// @brief Method to retrieve the ID of the input object.
		/// @return An integer representing the input's ID.
		int getID();
		
		/// @brief Method to retrieve the number of the button's answer that the input object represents.
		/// @return An integer representing the button's answer number.
		int getButtonNumber();
		
	private:
		int id; /// @brief The ID of the input object.
		int number; /// @brief The number of the answer button that the input object represents.
		bool state; /// @brief Whether the input device is on or not.
		const Player* player; /// @brief The player object associated with the input device.
		
};

#endif


