/*
 * Input creates and manipulates the hardware for user input.
 * 
 * The following class is the frame structur of the Input class type.
 * 
 */
#ifndef INPUT_H_
#define INPUT_H_
#include <iostream>
#include <wiringPi.h>

class Input{
		
	public:
		Input();
		Input(int ID);
		~Input();
		
		void update();
		bool getState();
		int getID();
		
	private:
		int id;
		bool state;
		
};

#endif


